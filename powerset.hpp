#pragma once
namespace itertools
{
    template <typename T>
    class powerset
    {
        private:
        T _start;

        public:

        powerset(T _sta) : _start(_sta) {

        }
        
        template <typename P>
        class iterator
        {
          private:
            P data1;
            P data2;

            public:
            iterator(P ptr1, P ptr2) : data1(ptr1), data2(ptr2) {

            }

            std::pair<decltype(*data1),decltype(*data2)> operator*() const {

             return  std::pair<decltype(*data1),decltype(*data2)> (*data1 , *data2);
            
            }

            iterator<P>& operator++() {

			    return *this;
            }

		    bool operator==(iterator<P> it) const {
			    return false;
		    }

		    bool operator!=(iterator<P> it) const {
			    return false;
            }
        };

        public:

        auto begin() { 
            return iterator<decltype(_start.begin())> (_start.begin(), _start.end()); 
        } 
        auto end()  { 
            return iterator<decltype(_start.begin())>(_start.end(), _start.end());
        } 

    };
}
