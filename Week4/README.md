# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is a word invented by the president of the National Puzzlers' League as a synonym for the disease known as silicosis. (wikipedia)
In case of this pset, it's an example of the longest word that can be stored and checked from dictionary.


## According to its man page, what does `getrusage` do?

 getrusage() returns resource usage measures.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members - timeval ru_utime; timeval ru_stime; ru_maxrss; ru_ixrss; ru_idrss; ru_isrss; ru_minflt; ru_majflt; ru_nswap; ru_inblock; ru_oublock; ru_msgsnd; ru_msgrcv; ru_nsignals; ru_nvcsw; ru_nivcsw;

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Passing 'before' and 'after' by value will copy the whole structures into 'calculate' - it's a waste of memory and time.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

for loop starts on line 71. We're initializing c, which gets us a char from the word, for loop goes until the EOF, we don't want to modify c, as we need to get a character from the words everytime.
On line 74 we're checking if a character is alphabetic(isalpha(c)) OR if it is an apostroph (c == '\'' && index > 0) (index should always be more than 0, because a dictionary doesn't allow a word to begin with apostroph).
If everything is okay, we apply a character to the word (77) by its index and increment the index by 1 (78). If index is more than const LENGTH(45 chars), that means that it's too long to be an allowed word, so we increment the index to 0
to prepare for a beginning of a new word. (80-89) On lines 90-91 we're ignoring the symbols which are not chars.
When we are getting to the symbol or a space - that means that we've found the whole word, so we reset the index to 0, terminate the word with '\0' and processing the algorithm until the end of the file.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc() reads character-by-character, so we can keep track of the number of chars we read, while using fscanf() might get us into trouble if a longer string than we expect was read.
This might overwrite other important data in memory or probably makes our program exist with a segmentation fault. fscanf() should be okay for reading in from the dictionary file, because the words are all separated by line returns.
But, fscanf() could cause problems if used to read in from the text file because words in that file will not always end with a space or line return. Many will be followed by a period or comma, which fscanf will see as being part
of the word.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

const char *word and const char *dictionary are not expected to be changed through the program so just to be sure we won't mess around with them.
