Show step by step how Merge Sort would sort the following list in ascending order
Clearly and neatly show and label all work

43   -   12   -   32   -   20   -   14   -   39   -   21   -   28   -   48    //Original List of 9 elements

43   -   12   -   32   -   20   -   14       39   -   21   -   28   -   48    //Split into 2 lists

43   -   12   -   32       20   -   14       39   -   21       28   -   48    //Split into 4 lists

43   -   12       32       20       14       39       21       28       48    //Split into 8 lists

43       12       32       20       14       39       21       28       48    //Split into 9 lists (Spliting stops here since all lists are each a size of 1)


12   -   43       20   -   32       14   -   39       21   -   28       48    //Combine into pairs (Ommited the 48 based on what was shown in the slides)

12   -   20   -   32   -   43       14   -   21   -   28   -   39       48    //Combine into pairs

12   -   14   -   20   -   21   -   28   -   32   -   39   -   43       48    //Combine into pairs

12   -   14   -   20   -   21   -   28   -   32   -   39   -   43   -   48    //Combine into pairs
