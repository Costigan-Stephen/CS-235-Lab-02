/***********************************************************************
 * Header:
 *    VECTOR
 * Summary:
 *    Our custom implementation of std::vector
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        vector                 : A class that represents a Vector
 *        vector::iterator       : An iterator through Vector
 * Author
 *    Stephen Costigan, Alexander Dohms, Jonathan Colwell
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <new>      // std::bad_alloc
#include <memory>   // for std::allocator


namespace custom
{

/*****************************************
 * VECTOR
 * Just like the std :: vector <T> class
 ****************************************/
template <typename T, typename A = std::allocator<T>>
class vector
{
public:
   
   //
   // Construct
   //
   vector(const A & a = A());
   vector(size_t numElements,                const A & a = A());
   vector(size_t numElements, const T & t,   const A & a = A());
   vector(const std::initializer_list<T>& l, const A & a = A());
   vector(const vector &  rhs);
   vector(      vector && rhs);
  ~vector();

   //
   // Assign
   //
   void swap(vector& rhs)
   {
   }
   vector & operator = (const vector & rhs);
   vector & operator = (vector&& rhs);

   //
   // Iterator
   //
   class iterator;
   iterator begin()
   {
    return iterator(data);
   }
   iterator end() 
   { 
    return iterator(data + size() - 1);
   }

   //
   // Access
   //
         T& operator [] (size_t index);
   const T& operator [] (size_t index) const;
         T& front();
   const T& front() const;
         T& back();
   const T& back() const;

   //
   // Insert
   //
   void push_back(const T& t);
   void push_back(T&& t);
   void reserve(size_t newCapacity);
   void resize(size_t newElements);
   void resize(size_t newElements, const T& t);

   //
   // Remove
   //
   void clear()
   {
   }
   void pop_back()
   {
   }
   void shrink_to_fit();

   //
   // Status
   //
   size_t  size()          const { return numElements;}
   size_t  capacity()      const { return numCapacity;}
   bool empty()            const { return (size() > 0 ? false : true);}
  
#ifdef DEBUG // make this visible to the unit tests
public:
#else
private:
#endif
   
   A    alloc;                // use alloacator for memory allocation
   T *  data;                 // user data, a dynamically-allocated array
   size_t  numCapacity;       // the capacity of the array
   size_t  numElements;       // the number of items currently used
};

/*****************************************
 * VECTOR :: NON-DEFAULT constructors
 * non-default constructor: set the number of elements,
 * construct each element, and copy the values over
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector(const A & a)
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}


/*****************************************
 * VECTOR :: NON-DEFAULT constructors
 * non-default constructor: set the number of elements,
 * construct each element, and copy the values over
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector(size_t num, const T & t, const A & a) 
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}

/*****************************************
 * VECTOR :: INITIALIZATION LIST constructors - Steve
 * Create a vector with an initialization list.
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector(const std::initializer_list<T> & l, const A & a) 
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}

/*****************************************
 * VECTOR :: NON-DEFAULT constructors
 * non-default constructor: set the number of elements,
 * construct each element, and copy the values over
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector(size_t num, const A & a) 
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}

/*****************************************
 * VECTOR :: COPY CONSTRUCTOR
 * Allocate the space for numElements and
 * call the copy constructor on each element
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector (const vector & rhs) 
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}
   
/*****************************************
 * VECTOR :: MOVE CONSTRUCTOR
 * Steal the values from the RHS and set it to zero.
 ****************************************/
template <typename T, typename A>
vector <T, A> :: vector (vector && rhs) 
{
   data = new T[100];
   numElements = 19;
   numCapacity = 29;
}

/*****************************************
 * VECTOR :: DESTRUCTOR - Steve
 * Call the destructor for each element from 0..numElements
 * and then free the memory
 ****************************************/
template <typename T, typename A>
vector <T, A> :: ~vector()
{
}

/***************************************
 * VECTOR :: RESIZE
 * This method will adjust the size to newElements.
 * This will either grow or shrink newElements.
 *     INPUT  : newCapacity the size of the new buffer
 *     OUTPUT :
 **************************************/
template <typename T, typename A>
void vector <T, A> :: resize(size_t newElements)
{
   numElements = 3;
}

template <typename T, typename A>
void vector <T, A> :: resize(size_t newElements, const T & t)
{
   numElements = 3;
}

/***************************************
 * VECTOR :: RESERVE
 * This method will grow the current buffer
 * to newCapacity.  It will also copy all
 * the data from the old buffer into the new
 *     INPUT  : newCapacity the size of the new buffer
 *     OUTPUT :
 **************************************/
template <typename T, typename A>
void vector <T, A> :: reserve(size_t newCapacity)
{
   numCapacity = 99;
}

/***************************************
 * VECTOR :: SHRINK TO FIT Alexander
 * Get rid of any extra capacity
 *     INPUT  :
 *     OUTPUT :
 **************************************/
template <typename T, typename A>
void vector <T, A> :: shrink_to_fit()
{
    T * dataNew = alloc.allocate(numElements);
   /*
    if (numElements == numCapacity)
        return;
    T * dataNew = alloc.allocate(numElements);
    
    for (int i = 0; i <= numElements; i++)
    {
        dataNew[i] = data[i];
    }
    for (int i = 0; i <= numElements; i++)
    {
        alloc.destroy(data[i]);
    }
    
    alloc.deallocate(data,numCapacity);
    delete(data);
    data = dataNew;
    numCapacity = numElements;
    */
    if (numElements == numCapacity) {
        return;
    }
    //dataNew = new T[numElements ];
    for (int i = 0; i <= numElements; i++) {
        dataNew[i] = data[i];
        
        alloc.destroy(&data[i]);
    }
    
    //alloc.destroy(&data[0]);
    data = dataNew;
    numCapacity = numElements;
}



/*****************************************
 * VECTOR :: SUBSCRIPT Alexander
 * Read-Write access
 ****************************************/
template <typename T, typename A>
T & vector <T, A> :: operator [] (size_t index)
{
   return *(data + index);
    
}

/******************************************
 * VECTOR :: SUBSCRIPT
 * Read-Write access
 *****************************************/
template <typename T, typename A>
const T & vector <T, A> :: operator [] (size_t index) const
{
   return *(data + index);
}

/*****************************************
 * VECTOR :: FRONT - Steve
 * Read-Write access
 ****************************************/
template <typename T, typename A>
T & vector <T, A> :: front ()
{
   return *(new T);
}

/******************************************
 * VECTOR :: FRONT - Steve
 * Read-Write access
 *****************************************/
template <typename T, typename A>
const T & vector <T, A> :: front () const
{
   return *(new T);
}

/*****************************************
 * VECTOR :: FRONT - Steve
 * Read-Write access
 ****************************************/
template <typename T, typename A>
T & vector <T, A> :: back()
{
   return *(new T);
}

/******************************************
 * VECTOR :: FRONT - Steve
 * Read-Write access
 *****************************************/
template <typename T, typename A>
const T & vector <T, A> :: back() const
{
   return *(new T);
}

/***************************************
 * VECTOR :: PUSH BACK Alexander
 * This method will add the element 't' to the
 * end of the current buffer.  It will also grow
 * the buffer as needed to accomodate the new element
 *     INPUT  : 't' the new element to be added
 *     OUTPUT : *this
 **************************************/
template <typename T, typename A>
void vector <T, A> :: push_back (const T & t)
{
    
}

template <typename T, typename A>
void vector <T, A> ::push_back(T && t)
{
    

}

/***************************************
 * VECTOR :: ASSIGNMENT Alexander
 * This operator will copy the contents of the
 * rhs onto *this, growing the buffer as needed
 *     INPUT  : rhs the vector to copy from
 *     OUTPUT : *this
 **************************************/
template <typename T, typename A>
vector <T, A> & vector <T, A> :: operator = (const vector & rhs)
{
   
   return *this;
}
template <typename T, typename A>
vector <T, A>& vector <T, A> :: operator = (vector&& rhs)
{

   return *this;
}


/**************************************************
 * VECTOR ITERATOR
 * An iterator through vector.  You only need to
 * support the following:
 *   1. Constructors (default and copy)
 *   2. Not equals operator
 *   3. Increment (prefix and postfix)
 *   4. Dereference
 * This particular iterator is a bi-directional meaning
 * that ++ and -- both work.  Not all iterators are that way.
 *************************************************/
template <typename T, typename A>
class vector <T, A> :: iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()                       { p = 0; }
   iterator(T * p)                  { this->p = p; }
   iterator(const iterator & rhs)   { p = rhs.p; }
   iterator & operator = (const iterator & rhs)
   {
       this->p = rhs.p;
       return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return (rhs.p != p ? true : false); }
   bool operator == (const iterator & rhs) const { return (rhs.p == p ? true : false); }

   // dereference operator
   T & operator * ()
   {
       return *p;
   }

   // prefix increment
   iterator & operator ++ ()
   {
       p++;
       return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
       iterator i = p;
       p++;
       return i;
   }

   // prefix decrement
   iterator & operator -- ()
   {
       p--;
       return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
       iterator i = p;
       p--;
       return i;
   }

#ifdef DEBUG // make this visible to the unit tests
public:
#else
private:
#endif
   T * p;
};


}; // namespace custom

