Show step by step how Quick Sort would sort the following list in ascending order using the first element sorting scheme.
Clearly and neatly show and label all work




(Gamradts Schema)
P = Pivot element
L = Left of pivot (smaller)
R = Right of pivot (larger)
()= Sorted

 43    -   12   -   32   -   20   -   14   -   39   -   21   -   28   -   48    //Original List of 9 elements
 P         L        L        L        L        L        L        L        L
 
 12    -   32   -   20   -   14   -   39   -   21   -   28      (43)      48    //
 P         R        R        R        R        R        R                 P

(12)   -   32   -   20   -   14   -   39   -   21   -   28               (48)  //
           P        L        L        L        L        L

           20   -   14   -   21   -   28      (32)      39                     //
           P        L        R        R                 P

           14   -  (20)  -   21   -   28               (39)                    //
           P                 P        R

          (14)              (21)       28                                      //List size 1 is sorted
                                       P

                                      (28)                                     //

Sorted List
12   -   14   -   20   -   21   -   28   -   32   -   39   -   43   -   48


________________________________________________________________
Full Work used to create the schema

 43    -   12   -   32   -   20   -   14   -   39   -   21   -   28   -   48    //Original List of 9 elements

(43)   -   12   -   32   -   20   -   14   -   39   -   21   -   28   -   48    //Select 43 as pivot
 12    -   32   -   20   -   14   -   39   -   21   -   28      (43)      48    //
 12    -   32   -   20   -   14   -   39   -   21   -   28                48    //Split list into halves

(12)   -   32   -   20   -   14   -   39   -   21   -   28               (48)  //Select 12 and 48 as the pivots of the 2 lists
(12)   -   32   -   20   -   14   -   39   -   21   -   28               (48)  //
           32   -   20   -   14   -   39   -   21   -   28                     //Split list into halves

          (32)  -   20   -   14   -   39   -   21   -   28                     //Select 32 as pivot
           20   -   14   -   21   -   28      (32)      39                     //
           20   -   14   -   21   -   28                39                     //Split list into halves - View according to Dr Gamradt's schema  

          (20)  -   14   -   21   -   28               (39)                    //Select 20 and 30 as pivots
           14   -  (20)  -   21   -   28               (39)                    //
           14                21   -   28                                       //

          (14)              (21)   -   28                                      //Select 14 and 21 as pivots
          (14)              (21)       28                                      //
                                       28                                      //

                                      (28)                                     //

_____________________________________________________________________________________                                    
Quick Glance View

43   -   12   -   32   -   20   -   14   -   39   -   21   -   28   -   48    // Original List of 9 elements
12   -   32   -   20   -   14   -   39   -   21   -   28                48    // After first partitioning
         32   -   20   -   14   -   39   -   21   -   28                      // After second partitioning
         20   -   14   -   21   -   28                39                      // After third partitioning
         14                21   -   28                                        // After fourth partitioning
                                    28                                        // After fifth partitioning

12   -   14   -   20   -   21   -   28   -   32   -   39   -   43   -   48    // Final sorted list