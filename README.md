![Logo](https://github.com/adamappsdev/PVLdeluxe/blob/master/PVLdeluxe.png)
### PVLdeluxe
A personal virtual library (PVL) app built in C.

The "delux" suffix is added as a tongue-in-cheek gesture.

### Use Case
One of the most life-changing discoveries of my life was when I began reading well-written books. It has become a sort-of hobby of mine to collect genres or lists of books to read later on websites such as Goodreads. However, while Goodreads is a functionally elegant website, some aspects of the design and application when making your own lists didn't match my own needs.

I tend to collect lists of books based on a specific genre and/or with an idea in mind. Most usually - I make the case for both. However, Goodreads does not support a "genre" selection for your own personally-curated lists.
Additionally, the ability to add a short description of what the list is about or what you're supposed to get out of reading all these books would be nice to have, too.

### C
I've been introduced to C through the online CS50 lectures from Harvard. I've decided to use C for this specific app because of its good performance as well as unversality of syntax, which can be translated into other coding languages with relative ease if such a need ever manifests. Additionally, there's something very visceral when you code in C, perhaps because it's closer to Assembly-level code than other popular languages.

### Specification
The app is a piece of software with CRUD functionality which outputs a single generated file that contains all the data you inputted. When launched, it takes the same file as an input for the capability to edit it through the app's interface. If no such file exists in the directory, it generates a new data file instead.

#### File Structure
Initial structure of how the data is organized is provided below:
```
index.c
authors
    lastname, fname
        booktitle1.txt
        booktitle2.txt
        booktitle3.txt
```
The year of publishing, among other information, is stored within the .txt files themselves.
