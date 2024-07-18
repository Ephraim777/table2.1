#include <iostream>
#include <cmath>
int real_string_hash(std::string& str, int p, int n)
{
    uint32_t member = 0;
    uint32_t current_p = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            member += static_cast<uint32_t>(str[i]);
        }
        else
        {
            current_p *= p;
            member += static_cast<uint32_t>(str[i]) * current_p;
        }

    }
    return static_cast<int>(member % n);
}

bool cheack_p(int p)
{
    if (p <= 1)
    {
        return false;
    }
    if (p <= 3)
    {
        return true;
    }

    if (p % 2 == 0 || p % 3 == 0) {
        return false;
    }

    for (int i = 5; i <= std::sqrt(p); i += 2)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int p;
    while (true)
    {
        std::cout << "Enter p\n";
        std::cin >> p;
        bool answer = cheack_p(p);
        if (answer)
        {
            break;
        }
    }
    std::cout << "Enter n\n";
    int n;

    std::cin >> n;
    while (true)
    {
        std::string str;
        std::cout << "Enter str\n";
        std::cin >> str;
        std::cout << "Hash str " << str << " " << real_string_hash(str, p, n) << std::endl;
        if (str == "exit")
        {
            break;
        }
    }

    return 0;
}
