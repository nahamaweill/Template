#pragma once

namespace itertools
{

    template <typename T>
    
    /*
    This class represents a range of objects.
    */
    class range
    {
        private:
        T _start; //The start of the range.
        T _end; //The end of the range.

        public:
        /*
        A copy constructor.
        */
        range(T start, T end) : _start(start), _end(end)
        {

        }

        /*
        A disconstructor.
        */
        ~range()
        {

        }

        /*
        This class represents a iterator.
        */
        class iterator
        {
            private:
            T dataPtr; //Pointer to the data.

            public:
            /*
            A copy constructor.
            */
            iterator(T ptr) : dataPtr(ptr)
            {

            }

            /*
            For operator *:
            */
            T operator*() const
            {
			    return dataPtr;
            }

            /*
            For operator ++:
            */
            iterator& operator++()
            {
                ++dataPtr;
			    return *this;
            }

            /*
            For operator ==:
            */
		    bool operator==(const iterator& rhs) const
            {
			    return (dataPtr == rhs.dataPtr);
		    }

            /*
            For operator !=:
            */
		    bool operator!=(const iterator& rhs) const
            {
			    return (dataPtr != rhs.dataPtr);
            }
        };

        public:
        /*
        Iterator for the start.
        */
        iterator begin()
        {
		    return iterator(_start);
	    }

        /*
        Iterator for the end.
        */
	    iterator end()
        {
		    return iterator(_end);
        }
    };
}
