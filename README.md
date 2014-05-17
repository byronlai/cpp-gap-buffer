# C++ Gap Buffer Implementation

A gap buffer implemented in C++. A gap buffer is a dynamic array that allows efficient insertion and deletion operations clustered near the same location. A lot of text editors use gap buffer as the underlying storage. Gap buffer is a good fit for text editors because most text editing operations are clustered near the same location.

## API

* `operator[](int index)`

  Return the item at the given index.

* `isFull()`

  Return true if the buffer is full.

* `shift(int count)`

   Shift all items to the left by the given amount.
   
* `seek(int index)`

   Set the cursor to the given position.

* `insert(T item)`

   Insert the given item at the position of the cursor.

* `remove()`

   Remove the item at the position of the cursor.

## See Also

* [Generic Gap Buffer](http://www.codeproject.com/Articles/20910/Generic-Gap-Buffer)
* [Gap buffer - Wikipedia](https://en.wikipedia.org/wiki/Gap_buffer)
