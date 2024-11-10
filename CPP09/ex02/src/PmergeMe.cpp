#include "PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
    //std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe( void )
{
    //std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe( std::list<double> List ): myList(List), myVector(List.begin(), List.end())
{
    //std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	//std::cout << "PmergeMe copy assignment operator called" << std::endl;
	this->myList = other.myList;
	this->myVector = other.myVector; 
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &cp)
{
	//std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = cp;
}

std::list<double>& PmergeMe::getList()
{
	return(this->myList);
}

std::vector<double>& PmergeMe::getVector()
{
	return(this->myVector);
}

void PmergeMe::merge(std::list<double> &myList, int left, int mid, int right)
{
    std::list<double>::iterator it = myList.begin();
    std::advance(it, left);
    std::list<double> L;
    std::list<double> R;

    for (int i = left; i <= mid; ++i)
    {
        L.push_back(*it);
        ++it;
    }
    for (int j = mid + 1; j <= right; ++j)
    {
        R.push_back(*it);
        ++it;
    }

    it = myList.begin();
    std::advance(it, left);
    std::list<double>::iterator itL = L.begin();
    std::list<double>::iterator itR = R.begin();
    while (itL != L.end() && itR != R.end())
    {
        if (*itL <= *itR) {
            *it = *itL;
            ++itL;
        } else {
            *it = *itR;
            ++itR;
        }
        ++it;
    }
    while (itL != L.end())
    {
        *it = *itL;
        ++itL;
        ++it;
    }
    while (itR != R.end())
    {
        *it = *itR;
        ++itR;
        ++it;
    }
}

void PmergeMe::merge(std::vector<double> &myVector ,int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<double> L(n1);
    std::vector<double> R(n2);
    int j = -1;
    int i = -1;
    
    while(++i < n1)
        L[i] = myVector[left + i];
    while(++j < n2)
        R[j] = myVector[mid + 1 + j];
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            myVector[left++] = L[i++];
        else
            myVector[left++] = R[j++];
    }
    while (i < n1) 
        myVector[left++] = L[i++];
    while (j < n2)
        myVector[left++] = R[j++];
}

