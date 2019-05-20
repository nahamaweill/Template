#pragma once
#include <cmath>

namespace itertools
{
    template <typename T>

    /*
    This class represents all the subsets of a container-like.
    */
    class powerset
    {
        private:
        T _start; //A container.

        public:
        /*
        A copy constructor.
        */
        powerset(T _sta) : _start(_sta)
        {

        }
        
        template <typename P>
        /*
        This class represents an iterator.
        */
        class iterator
        {
            private:
            P data1; //Pointer to the start data of the container.
            P data2; //Pointer to the end data of the container.
            unsigned size;
            unsigned size_group;


            public:
            /*
            A copy constructor.
            */
            iterator(P ptr1, P ptr2) : data1(ptr1), data2(ptr2), size(1), size_group(0)
            {
                while (data1 != data2) //Counting how many elements.                {
                    size++;
                    data1++;
                }
                data1 = ptr1;

                size_group = std::pow(2, size); //Calculating how many groups.
            }

            /*
            For operator *:
            */
            std::pair<decltype(*data1), decltype(*data2)> operator*() const
            {
                return  std::pair<decltype(*data1), decltype(*data2)> (*data1 , *data2);
            }

            /*
            For operator ++:
            */
            iterator<P>& operator++()
            {
			    return *this;
            }

            /*
            For operator !=:
            */
		    bool operator!=(iterator<P> it) const
            {
			    return false;
            }
        };

        public:

        /*
        This function returns the start of the powerset.
        */
        auto begin() const
        { 
            return iterator<decltype(_start.begin())> (_start.begin(), _start.end());
        }

        /*
        This function returns the end of the powerset.
        */
        auto end() const
        { 
            return iterator<decltype(_start.begin())>(_start.end(), _start.end());
        } 
    };
}
