#ifndef  RPN_HPP
# define  RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <deque> 

class RPN
{
    protected:

    private:
        std::deque<int> num;
    
    public:
        ~RPN(void);
        RPN(void);
        RPN(const RPN &cp);
		RPN& operator=(const RPN &other);
        void pushfrontQueue(int n);
        void pushbackQueue(int n);
        void popfrontQueue();
        void popbackQueue();
        void printDeque();
        int getSize();
        int operator[](size_t i);

        class ExceptionErr: public std::exception {
            virtual const char* what() const throw() {
                return "Err";
            }
        };
};

#endif
