#pragma once

namespace itertools
{
    template <typename T1, typename T2>

    /*
    This class represents A chaun of two containers-like.
    */
    class chain 
    {
        private:
        T1 _it1; //For the start.
        T2 _it2; //For the end.
        
        public:
        /*
        A copy constructor.
        */
        chain(T1 _start, T2 _end) : _it1(_start), _it2(_end)
        {

        }

        template <typename P1, typename P2>

        /*
        This class represents a iterator.
        */
        class iterator
        {
          private:
            P1 data1; //Pointer to the data of the first range.
            P2 data2; //Pointer to the data of the second range.

            public:
            /*
            A copy constructor.
            */
            iterator(P1 ptr1, P2 ptr2) : data1(ptr1), data2(ptr2)
            {

            }

            decltype(*data1) operator*() const
            {
			    return *data1;
            }

            /*
            For operator ++:
            */
            iterator& operator++()
            {
			    return *this;
            }

            /*
            For operator ==:
            */
		    bool operator==(iterator<P1,P2> it) const
            {
			    return false;
		    }

            /*
            For operator !=:
            */
		    bool operator!=(iterator<P1,P2> it) const
            {
			    return false;
            }
        };

        public:

        auto begin()
        {
            return iterator <decltype(_it1.begin()),decltype(_it2.begin())> (_it1.begin(), _it2.begin());;
        }

        auto end()
        {
            return iterator <decltype(_it1.end()),decltype(_it2.end())> (_it1.end(), _it2.end());;
        }

    };
}