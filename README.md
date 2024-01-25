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
### Parameters?
Whether and how many parameters to use will depend on whether keeping track of them would be considered to lower the algorithm efficiency. But if we had our hands untied, we could consider:
* The `largest number` / the `smallest number`
* The `indexes` (values **0 2 8 11 13** being indexed as **0 1 2 3 4**)
* The `how many values smaller than` the `current` 
* The `how many values greater than` the `current` 

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
* 2.a.3 verbose:
  * **15243** => `ra` `pb` `ra` `sa` `ra` `ra` `pa` `ra`
  * **Note**: I was convinced by Natalie to used linked lists. Which begs the question, how do you store information about the position (as in arr[pos]) in linked lists?
  * `int smallest`, `int next`, `step count`. Calculate to determine and assign 1 as the smallest. rm from `unsorted[]`
  * You have smallest, now look at stacks. [`smallest` happens to be within reach] <- formalize conditions here. `ra` the `smallest` => a: _5243**1** b: _____
    * Formalization of "if [`smallest` happens to be within reach]"
      * if `smallest` == a[0], then `ra`
      * else if `smallest` == a[1];
        * if `next` == a[0], then `sa` + `ra`
        * else `pb` + `ra`
      * else if `smallest` == a[z], then `0`
      * else if `smallest` == a[z - 1]
        * if `prev smallest` == a[z], **then what???**
        * else `rra`
      * else if `smallest` == b[0], then `pa` + `ra`
      * else if `smallest` == b[1]
        * if `next` == b[0], then `sb` + `pa` + `ra`
        * else `rb` + `pa` + `ra`
      * else if `smallest` == b[z], then `rrb` + `pa` + `ra`
      * else if `smallest` == b[z - 1], then `rrb` + `rrb` + `pa` + `ra`
      * **else** if `smallest` in **a**, then `pb`
      * **else** if `smallest` in **b**, then `rb` or `rrb`
        * add weigh: if b[pos] > size(b) / 2, then `rrb` until `smallest` is atop b
        * add weigh: if b[pos] <= size(b) / 2, then `rb` until `smallest` is atop b
  * Calculate new `smallest`, calculate new `next`. Double while loop. If (number being tested) !> `unsorted[i++]` then `smallest = (number being tested)`, else test next number from the array. rm it from `unsorted[]`.
  * You have smallest, now look at stacks. Atop **a** is not smallest, abottom **a** is smallest, atop **b** is nothing, abottom **b** is nothing. `pb` the 5 => a: _2431 b: **5**
#### 2.b: scenario (b)
We use `pa` to first send **largest** and then keep sending smaller and smaller values to the top of the stack a, ensuring that `pa` == sorted
  - b: 412
- pb
  - a: 5
  - b: 3412
