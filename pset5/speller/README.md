# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

 'pneumonoultramicroscopicsilicovolcanoconiosis' is the longest word in english language.

## According to its man page, what does `getrusage` do?

1.  According to its man page, getrusage takes 2 parameters, 'who' and '*usage'. getrusage returns resource usage measures depending upon what is passed as 'who' as a parameter.


## Per that same man page, how many members are in a variable of type `struct rusage`?

2.  There are 16 members in the variable of type 'struct usage'


## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

3.  We need to pass 'before' and 'after' by reference and not by value because even though we're not changing the value, they're value can change/vary depending on what else the IDE is doing at the time of the execution, hence 'before' and 'after' are passed by reference.


## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

4.  The code in the main function starts by checking whether the correct number of command line arguments are given or not
    Then we initialise 'before' and 'after' of 'struct rusage' data type. Also, the variables related to time are initialised and set to 0.
    If there are 3 command line arguments i.e. if the dictionary to be used is mentioned, that dictionary is loaded into memory but if not mentioned dictionaries/large is loaded as default.
    Before loading the dictionary the statistics are stored in 'before' and the statistics after loading the dictionary are loaded in 'after' variables to compare them later.
    If the dictionary could not be loaded the main menu returns exit code.
    The time taken to load the dictionary is calculated using the 'before' and 'after' variable and the time taken is stored in 'time_load'.
    Now, the text file that has to be checked for misspellings is opened in read mode.
    The variables index, misspelling and words are initialised and set to zero
    An array 'word' of length 45+1 is initialised of char data type.
    for loop begins by extracting the text file by each character until it reaches EOF(End Of File).
    For each character extracted, it is checked if it is an alphabet or a digit.
    If the charecter extracted is an alphabet or an apostrophe(only when the the index is greater than 0), it is entered into the 'word' array at 'index' and the value of index is incremented.
    If the character is extracted even after the value of index is more than LENGTH(45), while loop is used to skip the word, since the longest word in English is less than 45 and index is set to 0 so that new word can be extracted.
    If the character extracted is a digit, the remaining of the word is ignored by skipping it using while loop and index is set to 0 so that new word can be extracted.
    If the character extracted is neither an alphabet nor a digit and index is greater than 0 it means that a whole word is found. The character '\0' is appended to 'word' array to terminate it.
    The 'words' variable is incremented.
    The 'word' is passed as a variable to the function 'check'. As the name suggests it checks whether the word belongs to the dictionary in the memory and returns a boolean value.
    If the 'check' function returns 'true' it means that the words is spelled correctly according to the dictionary but if the function returns 'false' it means the word is misspelled according to the dictionary in the memory. The misspelled word is printed and the variable 'misspellings' is incremented.
    The statictics are recorded before and after the checking process and the time taken is calculated and assigned to 'time_check' variable.
    The index is set to zero to prepare for a new word.
    This process continues until EOF(End Of File) is reached. Once reached for loop is exited.
    The file is checked for any errors if any, error message is printed, the file is closed, unloades the dictionary from memory and exit code is returned.
    if no errors, the file is closed, the size of the dictionary is determined, the dictionary is unloaded from the memory and the time consumed to do these tasks is measured and recorded.
    At last, all the statistics are printed.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

5.  We use fgetc to read each character at a time so that we can check whether the number is an alphabet or not. If a digit occurs we can ignore the word and move to the next one using fgetc only.
    If fscanf is used we cannot detect an alphanumeric word. If a word is more thn 45 characters fscanf is not helpful unlike when fgetc is used. Using fscanf scanning unknown number of words is complicated.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

6.  The parameters of 'load' and 'check' are 'word' and 'dictionary', to prevent these values from changing in the load and check functions, these are declared as constants.
