#include <iostream>
#include <string>
using namespace std;


// Date class: It stores the release date of the movie and has compare function to compare the dates
class Date {
public:
    int day; // variable to store the day 
    int month; // variable to store the month 
    int year; // variable to store the year

    // contructor
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    // Function Compare: It takes a pointer to another 'Date' object called 'other' in the argument, returning an integer value 
    // Use to check the relation between the two dates
    int compare(Date* other)
    {
        //If the year given in the argument on is greater than the year of other, it returns 1
        if (year > other->year)
        {
            return 1;
        }
        //If the year given in the argument on is less than the year of other, it returns 1
        else if (year < other->year)
        {
            return -1;
        }

        // Now if the years are equal, it compares the month. And if months are also equal, it compares the day in the same manner as it comares the year

        // comparing month
        else if (month > other->month) {
            return 1;
        }
        else if (month < other->month) {
            return -1;
        }
        //comparing days
        else if (day > other->day) {
            return 1;
        }
        else if (day < other->day) {
            return -1;
        }

        // If day, month and year all are equal, the function returns 0
        else {
            return 0;
        }
    }
};

// Node class for DLL and CLL. Each nodes stores a movie title, date and the pointers to the next and prev nodes 
class Node {
public:
    string title; // declaring a string variable 'title' which stores the title of the movie
    Date* date; // declaring a pointer 'date' that points towards the date of the movie
    Node* next; // declaring a pointer 'next' that points towards the next node in the list
    Node* prev; // declaring a pointer 'prev' that points towards the previous node in the list

    // Constructor
    Node(string t, Date* d)
    {
        title = t;
        date = d;
        next = nullptr;
        prev = nullptr;
    }
};


// Category class (CLL): It stores movie name and a header pointer that points to CLL. 
// The member functions for this class includes functions incude addMovie to add a new movie, searchMovie to search a movie, getMovieIndex to get the index of the movie and lastly printAllMovies to print all the movies in different categories.

class Category {
public:
    string name; // intitializing string variable 'name' for the name of the category
    Node* header; // initializing a pointer 'header' that points towards the head of the list
    Category* next; // initializing a pointer 'next' that points towards the next node of the list
    Category* prev; //initializing a pointer 'prev' that points towards the previous node of the list

    // Cnnstructor
    Category(string n)
    {
        name = n;
        header = nullptr;
        next = nullptr;
        prev = nullptr;
    }

    // Function addMovie taking in two arguments the title of the movie and the released date
    void addMovie(string title, Date* date)
    {
        Node* newNode = new Node(title, date); // dynamically allocating memory for a new Node object and initializing it with the title and date arguments.

        if (header == nullptr)
        {
            // If the list is empty, we first assign 'header' pointer to the new node and points 'next' and 'prev' pointer to itself, in order to create a CLL with a single node
            header = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
        }

        else
        {
            // If the list is not empty, the execution continues, creating two pointers 'curr' and 'prev' and pointing them to header and nullptr respetively. 
            Node* curr = header;
            Node* prev = nullptr;
            bool found = false; // Initializing a bool variable 'found' to false.

            // loop to search for the correct position to add a new node, starting from the header node and running till we reach header node again
            do {
                if (title.compare(curr->title) < 0) // checks if the title of the new node(Node to be added) is less than the title of the current node
                {
                    found = true;
                    break;
                }
                // if the condition is not true, we update the prev and the current pointer
                prev = curr;
                curr = curr->next;
            } while (curr != header);

            if (found) // checks if the value of 'found' is true
            {
                // if yes, we insert the new node before current node
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev->next = newNode;
                curr->prev = newNode;
                if (curr == header) {
                    header = newNode;
                }
            }
            else
            {
                // if not, we insert the new node after previous node
                newNode->next = header;
                newNode->prev = prev;
                prev->next = newNode;
                header->prev = newNode;
            }
        }
    }

    // Function 'searchMovie' which takes the title as the argument and search for a movie, returning the node with the given title otherwise NULL
    Node* searchMovie(string title)
    {
        Node* curr = header; // setting the current node as the header node
        if (curr == nullptr) // if the header node in NULL, we return NULL
        {
            return nullptr;
        }

        do  // loop to iterate until we come back to the header node 
        {
            if (curr->title == title) // if the title of the current node matches the title taken in the argument, we return the current node
            {
                return curr;
            }
            curr = curr->next; // moving to the next node
        } while (curr != header);

        return nullptr; // if no node is found with the matching title, we return NULL
    }

    // Function 'getMovieIndex' which takes title as the argument and returns the index of the movie with the given title, otherwise  
    int getMovieIndex(string title)
    {
        Node* curr = header; // setting the current node as the header node
        if (curr == nullptr) // if header node was NULL, we return -1 indicating no movies were found
        {
            return -1;
        }

        int index = 0; // initializing a variable 'index' with value o

        do   // loop to iterate until we come back to the header node 
        {
            if (curr->title == title) // if the title of the current node matches the given title to the function, we return the current index 
            {
                return index;
            }
            curr = curr->next; // moving to the next node
            index++; // updating the value of index by 1
        } while (curr != header);

        return -1; // if no movie was found with the given title, we return -1
    }

    // Function 'printAllMovies' to print all the movies in the list
    void printAllMovies()
    {
        cout << "Category: " << name << endl; // printing the category name
        Node* curr = header; // setting the current node as the header
        if (curr == nullptr) // if the header node is NULL, we print no movies were found
        {
            cout << "No movies found in this category." << endl;
        }
        else
        {
            do // loop to iterate until we come back to the header node 
            {
                cout << curr->title << endl; // printing the title of the movie for the current node
                curr = curr->next; // moving to the next node
            } while (curr != header);
        }
    }
};

// DLL class: It stores all the categories and the memeber functions include addCategory to add a category in the list, searchCategory to search a cateory, searchMovie to find a movie in any category and removeCategory to remove  category
class DLL {
public:
    Category* head; // Pointer to the first category node
    // constructor
    DLL() {
        head = nullptr;
    }

    // Function 'addCategory' takes 'Name' as the argument 
    void addCategory(string name)
    {
        Category* newCategory = new Category(name); // dynamically allocating memory for a new Node object and initializing it with the title arguments.

        if (head == nullptr) // If the list is empty, we intialize the new category as the header 
        {
            head = newCategory;
        }
        else // otherwise, we add a new category in the end of the list
        {
            Category* current = head;
            while (current->next != nullptr) // iterating through the list until we find the last node         
            {
                current = current->next;
            }
            current->next = newCategory; // We set the next pointer of the 'last' category to the 'new' category
            newCategory->prev = current; // And we set the prev pointer of the 'new' category to the 'last' category
        }
    }

    // Function 'searchCategory' which takes name of the movie as the argument and returns the node which matches the title(name) of the movie taken in the function
    Category* searchCategory(string name)
    {
        Category* current = head; // setting the current pointer to the head of the list
        while (current != nullptr) // interating till the end of the list
        {
            if (current->name == name) // if the name of the current node matches the name taken by the function, we return that node
            {
                return current;
            }
            current = current->next; // moving the pointer to the next node
        }

        return nullptr; // if the category is not found, we return NULL
    }

    // Function 'searchMovie' which takes the title as the argument and search for a movie, returning the node with the given title otherwise NULL
    Node* searchMovie(string title)
    {
        Category* current = head; // setting the current pointer the point to the head node
        while (current != nullptr) // iterating till the end of the list
        {
            Node* result = current->searchMovie(title); // initializing a pointer 'result' which points towards the title of the current node
            if (result != nullptr) // if the pointer 'result' is not NULL, we return that title 
            {
                return result;
            }
            current = current->next; // moving the pointer to the next node
        }

        return nullptr; // if the movie is not found, we return NULL
    }

    // Function 'removeCategory' takes name as the argument
    void removeCategory(string name)
    {
        Category* categoryToRemove = searchCategory(name); // initializing a pointer 'categoryToRemove' pointing toward the category with the given name 

        if (categoryToRemove == nullptr) // if the pointer 'categoryToRemove' is NULL, we return 0
        {
            return;
        }

        Node* current = categoryToRemove->header; // Setting the 'current' pointer to the head of the list
        while (current != categoryToRemove->header) // iterating till the end of the list and deleting each node
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        // Updating the linked list pointers to remove the category
        if (categoryToRemove->prev == nullptr) {
            head = categoryToRemove->next;
        }
        else {
            categoryToRemove->prev->next = categoryToRemove->next;
        }
        if (categoryToRemove->next != nullptr) {
            categoryToRemove->next->prev = categoryToRemove->prev;
        }

        delete categoryToRemove; // Laslty deleting the category
    }

    // 'deleteMovie' function takes pointer to an object 'date' as the argument
    void deleteMovies(Date* date)
    {
        Category* current = head;
        while (current != nullptr)  // iterating till the end of the list
        {
            Node* movieToRemove = current->header; // // Initializing pointer 'movieToRemove' to  point to the header of the current category
            while (movieToRemove != nullptr) // iterating till the end of the list and deleting the movies
            {
                Node* temp = movieToRemove;
                movieToRemove = movieToRemove->next;
                delete temp;
            }

            current->header = movieToRemove;  // pointing the header of the linked list of movies to the current category

            // Updating the pointers for the first movie in the linked list
            if (current->header != nullptr)
            {
                current->header->prev = current->header->prev->prev;
                current->header->prev->next = current->header;
            }

            current = current->next; // moving to the next node
        }
    }

    // Function 'printAllMovies' is used to print all the movies in specific category
    void printAllMovies()
    {
        Category* current = head; // Initializing a 'current' pointer to point to the head node
        while (current != nullptr) // Iterating till the end of the list
        {
            cout << "Category: " << current->name << endl; // Printing the category name
            current->printAllMovies(); // Printing all the movies in that category
            current = current->next; // moving to the next category
        }
    }
};


int main() {
    // create the DLL object
    DLL* movieList = new DLL();

    // add categories to the DLL
    movieList->addCategory("Action");
    movieList->addCategory("Comedy");
    movieList->addCategory("Drama");

    // add movies to the categories
    Date* releaseDate1 = new Date(10, 12, 2022);
    movieList->searchCategory("Action")->addMovie("Spiderman: No Way Home", releaseDate1);

    Date* releaseDate2 = new Date(23, 11, 2021);
    movieList->searchCategory("Comedy")->addMovie("Ghostbusters: Afterlife", releaseDate2);

    Date* releaseDate3 = new Date(25, 12, 2022);
    movieList->searchCategory("Drama")->addMovie("The King's Man", releaseDate3);

    Date* releaseDate4 = new Date(11, 11, 2022);
    movieList->searchCategory("Action")->addMovie("Doctor Strange in the Multiverse of Madness", releaseDate4);

    // search for a movie and print its information
    cout << "\n1.Searching for the movie 'Ghostbusters: Afterlife' :\n\n";
    Node* searchResult = movieList->searchMovie("Ghostbusters: Afterlife");
    if (searchResult != nullptr) {
        cout << "Title: " << searchResult->title << endl;
        cout << "Release Date: " << searchResult->date->day << "-" << searchResult->date->month << "-" << searchResult->date->year << endl;
        cout << "Category: " << searchResult->prev->date << endl;
    }
    else {
        cout << "Movie not found." << endl;
    }

    // print all the movies in each category
    cout << "\n2.Printing all the movies in each category: \n\n";
    movieList->searchCategory("Action")->printAllMovies();
    cout << "\n";
    movieList->searchCategory("Comedy")->printAllMovies();
    cout << "\n";
    movieList->searchCategory("Drama")->printAllMovies();

    // remove a category
    movieList->removeCategory("Comedy");

    // search for a category that doesn't exist
    cout << "\n3.Searching for a category (comedy) after removing it: \n\n";
    Category* nonExistentCategory = movieList->searchCategory("Comedy");
    if (nonExistentCategory != nullptr) {
        cout << "Found category: " << nonExistentCategory->name << endl;
    }
    else {
        cout << "Category not found.\n" << endl;
    }

    // deallocate the memory used by the objects
    delete releaseDate1;
    delete releaseDate2;
    delete releaseDate3;
    delete releaseDate4;
    delete movieList;

    return 0;
}



