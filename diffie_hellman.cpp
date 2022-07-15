#include <iostream>
#include <cstdlib>

using namespace std;

uint32_t fastPow(uint32_t x, uint32_t y, uint32_t mod);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    uint32_t g = rand();
    uint32_t p = rand();
    cout << "Алисе и Бобу известны некоторые числа g: " << g << " и p: " << p << endl;
    uint32_t a = rand();
    cout << "Алиса выбирает случайное число a: " << a << endl;
    uint32_t b = rand();
    cout << "Боб выбирает случайное число b: " << b << endl;
    uint32_t A_ = (uint32_t)fastPow(g, a, p);
    cout << "Алиса вычисляет число A: " << A_ << " и пересылает его Бобу" << endl;
    uint32_t B_ = (uint32_t)fastPow(g, b, p);
    cout << "Боб вычисляет число B: " << B_ << " и пересылает его Алисе" << endl;
    uint32_t K_Alice = fastPow(B_, a, p);
    uint32_t K_Bob = fastPow(A_, b, p);
    cout << "Алиса и Боб вычисляют общий ключ" << endl;
    cout << "Теперь Алиса и Боб имеют ключ: " << K_Alice << " и " << K_Bob << endl;

    system("pause");
    return 0;
}

uint32_t fastPow(uint32_t x, uint32_t y, uint32_t mod)
{
    if (y == 0)
    {
        return x;
    }
    else if (y % 2 == 0)
    {
        return fastPow(x * x % mod, y / 2, mod);
    }
    else
    {
        return x * fastPow(x, y - 1, mod) % mod;
    }
}