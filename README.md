# push_swap
features stack (abstract), stack operations (swap, push, rotate and reverse), sorting, efficiency, computational complexity, getting next line

________________________________________________
## Available operations

Beginning state | Operation applied | final state
----- | :------: | ------
a: 01234 <br> b: 56789 | sa <br> (swap a) | a: **10**234 <br> b: 56789
a: 01234 <br> b: 56789 | sb <br> (swap b) | a: 01234 <br> b: **65**789
a: 01234 <br> b: 56789 | ss <br> (swap a + swap b) | a: **10**234 <br> b: **65**789
a: 01234 <br> b: 56789 | pa <br> (push to a) | a: **5**01234 <br> b: _6789
a: 01234 <br> b: 56789 | pb <br> (push to b) | a: _1234 <br> b: **0**56789
a: 01234 <br> b: 56789 | ra <br> (rotate a) | a: _1234**0** <br> b: 56789
a: 01234 <br> b: 56789 | rb <br> (rotate b) | a: 01234 <br> b: _6789**5**
a: 01234 <br> b: 56789 | rr <br> (ra + rb) | a: _1234**0** <br> b: _6789**5**
a: 01234 <br> b: 56789 | rra <br> (reverse rotate a) | a: **4**0123_ <br> b: 56789
a: 01234 <br> b: 56789 | rrb <br> (reverse rotate b) | a: 01234 <br> b: **9**5678_
a: 01234 <br> b: 56789 | rrr <br> (reverse rotate b) | a: **4**0123_ <br> b: **9**5678_

________________________________________________
a: 21543\
b: _____

- pb
  - a: 1543
  - b: 2
- pb
  - a: 543
  - b: 12
- ra
  - a: 435
  - b: 12
- pb
  - a: 35
 
________________________________________________

## Algorithm considerations
### 1: Bubble sort
Wouldn't work because we don't have access to a swapping operation that can work over an entire list. `sa` only works on list indexes [0] and [1].
### 2: Insertion sort
It's looking right, but again the operations available to us are less than ideal. For efficiency reasons, we need to define two scenarios:

**5096128347**

#### 2.a: scenario (a)
We use `ra` to first send **smallest** and then keep sending larger and larger values to the bottom of the stack a, ensuring that `ra` == sorted
* 2.a.1:
  * we `pb` until the smallest number comes on top of a, indicating that a is sorted so far.
  * we `rb` until we find `thenextnumber`? (assume we kept track)
  * we `pa` and `ra` and the next number is sorted. Now `thenextnumber++` happens.
* 2.a.2:
  * we `pb` until the smallest number comes on top of a, indicating that a is sorted so far.
  * we `rb` or `sb` or `rrb` depending which would get to `thenextnumber` more quickly. To find out, we iterated to look for it.
  * we `pa` and `ra` and the next number is sorted. Now `thenextnumber++` happens.
#### 2.b: scenario (b)
We use `pa` to first send **largest** and then keep sending smaller and smaller values to the top of the stack a, ensuring that `pa` == sorted
  - b: 412
- pb
  - a: 5
  - b: 3412
