#pragma once
namespace itertools
{
    template <typename T1, typename T2>
    class chain 
    {
        private:
        T1 _it1;
        T2 _it2;
        
        public:
        chain(T1 _start, T2 _end) : _it1(_start), _it2(_end) {

        }

        template <typename P1, typename P2>
        class iterator
        {
          private:
            P1 data1;
            P2 data2;

            public:
            iterator(P1 ptr1, P2 ptr2) : data1(ptr1), data2(ptr2) {

            }

            decltype(*data1) operator*() const {
			    return *data1;
            }

            iterator& operator++() {

			    return *this;
            }

		    bool operator==(iterator<P1,P2> it) const {
			    return false;
		    }

		    bool operator!=(iterator<P1,P2> it) const {
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