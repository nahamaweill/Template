#pragma once
namespace itertools{
    template <typename T>
    class range
    {
        private:
        T start;
        T end;

        public:

        range(T _start, T _end) : start(_start), end(_end) {

        }

        ~range(){

        }

        class iterator
        {
            private:
            T data;

            public:
            iterator(T ptr = NULL) : data(ptr) {

            }

            T& operator*() const {
			    return data;
            }

            iterator& operator++() {
                ++data
			    return *this;
            }

		    bool operator==(const iterator& rhs) const {
			    return (data == rhs->data);
		    }

		    bool operator!=(const iterator& rhs) const {
			    return (data != rhs->data);
            }
        };

        public:

        iterator begin() {
		    return iterator(start);
	    }
	
	    iterator end() {
		    return iterator(end);
        }

    };
}
