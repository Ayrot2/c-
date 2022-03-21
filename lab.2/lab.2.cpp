#include <iostream>
#include <iomanip>
using namespace std;

float mean(float integral_sum[], float const dv, int size) {
    float sum = 0.f;
    for (int i = 0; i < size; i++) {
        sum += integral_sum[i];
    }
    return dv * sum;
}

float rec_sum(float integral_sum[], int r_idx, int l_idx, float sum) {
    if (r_idx - l_idx == 1) return integral_sum[l_idx] + integral_sum[r_idx];
    if (r_idx - l_idx == 2) return integral_sum[l_idx] + integral_sum[l_idx+1]
        + integral_sum[r_idx];
    int center = (l_idx + ((r_idx - l_idx) / 2));
    sum += rec_sum(integral_sum,center, l_idx, sum)
        + rec_sum(integral_sum, r_idx, center+1, sum);
    return (sum);
}

float recursion (float integral_sum[], float const dv, int size) {
    float sum = 0.f;
    return rec_sum(integral_sum,size-1,0,0) * dv;
}

float d_s_sum(float int_sum[], int size, int c) {
    for (int i = 0; i +c < size; i += c * 2) {
        int_sum[i] = int_sum[i] + int_sum[i + c];
    }
    if (c*2 >= size) return int_sum[0];
    d_s_sum(int_sum, size, c*2);
}

float double_step(float integral_sum[], float const dv, int size) {
    float int_sum[1001];
    for (int i = 0; i < size; i++) {
        int_sum[i] = integral_sum[i]; // создаём массив-клон
    }
    int_sum[size] = 0; //на случай, если в массиве нечётное число элементов
    return d_s_sum(int_sum, size,1)*dv;     
}

float Kahan_sum(float integral_sum[], float const dv, int size) {
    float sum = 0.f;
    float t = 0.f;
    float y = 0.f;
    float z = 0.f;
    for (int i = 0; i < size; i++) {
        y = integral_sum[i] - t;
        z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    return sum*dv;
}

void Split(float const x, float &x_h, float &x_l) {
    auto c = static_cast<float>((1ul << 11) + 1ul);
    x_h = (c * x) + (x - (c * x));
    x_l = x - x_h;
}
float two_mult(float psi, float pdf) {
    float psi_h, psi_l, pdf_h, pdf_l;
    Split(psi,psi_h,psi_l);
    Split(pdf, pdf_h, pdf_l);
    float t, s;
    s = psi*pdf;
    t = psi_h * pdf_h + psi_h * pdf_l + psi_l * pdf_h + psi_l * pdf_l - s;
    return t + s;
}

double double_mean(double integral_sum_d[], double const dv_d, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += integral_sum_d[i];
    }
    return dv_d * sum;
}

void psi_input(float psi[], float T, float const dv, int size)
{
    for (int i = 0; i < size; i++)
        psi[i] = dv * i + dv / 2;
}

void pdf_input(float pdf[], float T, float const dv, int size, float const f_pi)
{
    float v = 0;
    for (int i = 0; i < size; i++)
    {
        v = dv * i + dv / 2;
        pdf[i] = exp(-v * v / T) / sqrt(T * f_pi);
    }
}

void psi_input_d(double psi_d[], float T, double const dv, int size)
{
    for (int i = 0; i < size; i++)
        psi_d[i] = dv * i + dv / 2;
}

void pdf_input_d(double pdf_d[], float T, double const dv_d, int size, double const d_pi)
{
    double v = 0;
    for (int i = 0; i < size; i++)
    {
        v = dv_d * i + dv_d / 2;
        pdf_d[i] = exp(-v * v / T) / sqrt(T * d_pi);
    }
}


int main()
{
    const float dv = 0.001f;
    unsigned const size = 1000;
    float const T = 295;
    float const f_pi = 3.14159265359f;
    float psi[size] = { 0 };
    float pdf[size] = { 0 };
    psi_input(psi, T, dv, size);
    pdf_input(pdf, T, dv, size,f_pi);
    float integral_sum[size];
    for (int i = 0; i < size;i++) {
        integral_sum[i] = two_mult(psi[i],pdf[i]);
    }

    const double dv_d = 0.001;
    double psi_d[size] = { 0 };
    double pdf_d[size] = { 0 };
    double const d_pi = 3.14159265359;
    double integral_sum_d[size];
    psi_input_d(psi_d, T, dv_d, size);
    pdf_input_d(pdf_d, T, dv_d, size, d_pi);
    for (int i = 0; i < size; i++) {
        integral_sum_d[i] = psi_d[i]*pdf_d[i];
    }
    cout << setprecision(6) << scientific;
    cout << mean(integral_sum,dv,size) << "  " << "\n";
    cout << recursion(integral_sum,dv,size) << "  "<<"\n";
    cout <<double_step(integral_sum, dv, size)<<" "<<"\n";
    cout << Kahan_sum(integral_sum, dv, size) << " "<<"\n";
    cout << double_mean(integral_sum_d, dv_d, size);
}

