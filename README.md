# -FILE-MANAGEMENT-TOOL
Company: "CODETECH IT SOLUTIONS"
Name: SHREEYA WATTAMWAR
Intern ID:CT04DY2687
Domain: C++
Duration :4 weeks

# YOU HAVE TO ENTER DESCRIPTION OF YOUR TASK (IN 500 WORDS)
### Internship Task 1: Building a C++ File Manager

This task was all about getting hands-on with **C++ file handling**—the foundation for how programs read and save data. My mission was to build a simple, reliable **File Management Tool** that could handle the three most basic file operations: **read, write, and append**.

I created a simple console application with a menu for the user. Here’s what it can do:

1.  **Write (or Overwrite) Files:** I used the **`std::ofstream`** class. If you write to a file, the program will **create it** if it doesn't exist. If the file is already there, it automatically **clears the old content** and replaces it with the new text you provide. It’s the digital equivalent of hitting "Save As" and overwriting the previous version.

2.  **Append to Files:** This is for making updates. I used **`std::ofstream`** again but added the crucial **`std::ios::app`** flag. This tells the program, "Don't touch the existing data; just find the very end of the file and start typing your new content there." It's perfect for log files or adding notes without deleting anything.

3.  **Read Files:** This involves the **`std::ifstream`** class. To make the program user-friendly, I made sure it won't crash if you try to read a file that hasn't been created yet—it just silently opens an empty file instead of throwing an error. Once open, it uses a reliable loop (`std::getline()`) to pull the text out **line by line** and display it clearly on the screen.

In short, the project proved I can handle the basics of **C++ file streams**, manage resources correctly, and write clean code that knows how to talk to the file system.
