// #pragma once
// #include <iostream>
// namespace itertools
// {
//     template <typename T1, typename T2>
//     class powerset 
//     {
//         private:
//         T1 _it1;
//         T2 _it2;
        
//         public:
//         powerset(T1 _start, T2 _end) : _it1(_start), _it2(_end) {

//         }
        
//         template <typename P1, typename P2>
//         class iterator
//         {
//           private:
//             P1 data1;
//             P2 data2;

//             public:
//             iterator(P1 ptr1, P2 ptr2) : data1(ptr1), data2(ptr2) {

//             }

//             std::pair<decltype(*data1),decltype(*data2)> operator*() const {

//              return  std::pair<decltype(*data1),decltype(*data2)> (*data1 , *data2);
// }

//             iterator<P1, P2>& operator++() {

// 			    return *this;
//             }

// 		    bool operator==(iterator<P1,P2> it) const {
// 			    return false;
// 		    }

// 		    bool operator!=(iterator<P1,P2> it) const {
// 			    return false;
//             }
//         };

//         public:

//         auto begin()
//         {
//             return iterator <decltype(_it1.begin()),decltype(_it2.begin())> (_it1.begin(), _it2.begin());;
//         }

//         auto end()
//         {
//             return iterator <decltype(_it1.end()),decltype(_it2.end())> (_it1.end(), _it2.end());;
//         }

        

        
//     };
    
//     // template <typename T1,typename T2>
//     // ostream &operator<<(ostream &os, const std::pair<T1,T2> &c) 
//     // {
//     //     os << c.first << "," << c.second ;
//     //     return os;
        
//     // }
// }

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
