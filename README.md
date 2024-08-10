# Password-Strength-Checker

This project is a Password Strength Checker built using GTK in C. It evaluates the strength of passwords and offers suggestions to improve them.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/x33MH/Password-Strength-Checker.git
   cd password-checker
Install dependencies:

2. **Install dependencies:**
   **For GTK on Linux
      sudo apt-get install libgtk-3-dev

   **For GTK on Windows using MSYS2:
      pacman -S mingw-w64-x86_64-gtk3

3. **Compile the project**
      gcc -o password_checker password_checker.c $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)


## Features
   -Real-time password strength evaluation
   -Suggestions to improve password strength
   -Toggle password visibility
   
## Contributing
   Contributions are welcome! Please follow these steps to contribute:

   Fork the repository.
   Create a new branch (git checkout -b feature-branch).
   Make your changes.
   Commit your changes (git commit -m 'Add some feature').
   Push to the branch (git push origin feature-branch).
   Open a Pull Request.

## License
   This project is licensed under the MIT License - see the LICENSE file for details.

   
      This structure should give a good balance between being informative and concise. You can add or remove sections based on the specifics of your project.
