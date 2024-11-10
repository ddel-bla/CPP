#ifndef  PMERGEME_HPP
# define  PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

class PmergeMe
{
    protected:

    private:
        std::list<double> myList;
        std::vector<double> myVector;
    
    public:
        ~PmergeMe(void);
        PmergeMe(void);
        PmergeMe( std::list<double> List );
		PmergeMe& operator=(const PmergeMe &other);
        PmergeMe(const PmergeMe &cp);
        std::list<double>& getList();
        std::vector<double>& getVector();
        void merge(std::list<double> &myList, int left, int mid, int right);
        void merge(std::vector<double>& myVector ,int left, int mid, int right);

        template<typename Container>
        void printContainer(const Container& container)
        {
            typename Container::const_iterator it = container.begin();
            int i = -1;

            while(it != container.end() && ++i < 5)
            {
                std::cout << *it << " ";
                it++;
            }
            if(i == 5)
                std::cout << "[ ... ]";
            std::cout << std::endl;
        }

        template <typename Container>
        void johnsonSort(Container& contenedor)
        {
            int n = contenedor.size();
            
            for (int size = 1; size < n; size *= 2) {
                for (int left = 0; left < n; left += 2 * size) {
                    int mid = std::min(left + size - 1, n - 1);
                    int right = std::min(left + 2 * size - 1, n - 1);
                    if (mid < right) {
                        merge(contenedor, left, mid, right);
                    }
                }
            }
        }
};

#endif
