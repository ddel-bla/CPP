#include "RPN.hpp"

void ft_aux(RPN& num, int n)
{
    num.popfrontQueue();
    num.popfrontQueue();
    num.pushfrontQueue(n);
}

void ft_calculator(RPN& num, char simbol)
{
    if(num.getSize() < 2)
        throw RPN::ExceptionErr();
    switch (simbol)
	{
		case '+':
            ft_aux(num, num[1] + num[0]);
			break;
		case '-':
            ft_aux(num, num[1] - num[0]);
			break;
		case '*':
            ft_aux(num, num[1] * num[0]);
			break;
		case '/':
            if (num[0] == 0)
                throw RPN::ExceptionErr();
            ft_aux(num, num[1] / num[0]);
			break;
        default:
            throw RPN::ExceptionErr();
	}
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Error: Invalid Arguments." << std::endl;
        return 1; 
    }

    size_t len = strlen(argv[1]);
    bool c = false;
    RPN num;

    try {
        for(size_t i = 0; i < len; i++)
        {
            if (isdigit(argv[1][i]))
            {
                if(c == true)
                    throw RPN::ExceptionErr();
                num.pushfrontQueue(argv[1][i] - '0');
                c = true;
            }
            else
            {
                if(argv[1][i] == '+' || argv[1][i] == '-' || 
                argv[1][i] == '*' || argv[1][i] == '/' || argv[1][i] == 32)
                {
                    if(argv[1][i] != 32)
                        ft_calculator(num, argv[1][i]);
                    c = false;
                }
                else
                    throw RPN::ExceptionErr();
            }
        }
        if(num.getSize() > 1)
            throw RPN::ExceptionErr();
        num.printDeque();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}