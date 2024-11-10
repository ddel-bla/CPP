#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Error: Invalid Arguments." << std::endl;
        return 1; 
    }

    double aux;
    double time;
    clock_t start, end;
    std::list<double> myList;
    for(int i = 1; i < argc; i++)
    {
        for(size_t j = 0; j < strlen(argv[i]); j++)
        {
            if(!isdigit(argv[i][j]))
            {
                std::cerr << "Err" << std::endl;
                return 1;
            }
        }
        aux = strtod(argv[i], NULL);
        if(std::find(myList.begin(), myList.end(), aux) != myList.end())
        {
            std::cerr << "Err" << std::endl;
            return 1;
        }
        myList.push_back(aux);
    }

    PmergeMe num(myList);

    std::cout << "Antes: ";
    num.printContainer(num.getList());

    start = clock();
    num.johnsonSort(num.getList());
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Despues: ";
    num.printContainer(num.getList());
    
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list " << time * 1000 << " ms." << std::endl;

    start = clock();
    num.johnsonSort(num.getVector());
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector " << time * 1000 << " ms." << std::endl;
}