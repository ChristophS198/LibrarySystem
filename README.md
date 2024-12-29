@page Readme Readme
# LibrarySystem
Implementation of a library system

# Next Steps
- incorporate doxygen in qmake
- write requirements for GUI and Logic
- finish UML diagram


## Media Management
- contains the media database and is responsible for adding/removing/chaning the database content
- exposes an interface to all classes that need access to the database 
A GUI dialog allows the user to add new media. Based on the type of media, different attributes can be entered.
This information is then transferred to the logic part of the Media Management which then creates a "loan medium" before adding it to the database.  
The Media Management receives a Medium and packages it into a "loan medium" by extending it with additional features like availability, due date and so on.

### Media Search
In my opinion the search module is very strongly coupled to the type of database. Therefore, I see no benefit in trying to completely decouple the search (interface) from the MediaManagement class. This only makes sense, if it is possible to reduce the MediaManagement interface to always provide its data in the same form (e.g. a map of some kind). 

## Loan Manager


