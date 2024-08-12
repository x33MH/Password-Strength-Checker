# Password-Strength-Checker

This project is a Password Strength Checker built using GTK in C. It evaluates the strength of passwords and offers suggestions to improve them.

## Installation

1. **Clone the repository:**
   
   ```bash
      git clone https://github.com/x33MH/Password-Strength-Checker.git
      cd password-checker

2. **Install dependencies:**
   
      Here’s how you can install GTK on Windows:
   
   Step 1: Install MSYS2
   
      MSYS2 is a software distribution and building platform for Windows that provides a Unix-like environment and package management system.
   
   Download MSYS2:
   
      Visit the MSYS2 website and download the installer.
      
      Run the installer and follow the prompts to install MSYS2. Choose a directory where MSYS2 will be installed (e.g., C:\msys64).
      
   Update the Package Database:
   
      After installation, open the MSYS2 terminal (MSYS2 UCRT64 is recommended).
      
      Update the package database and core system packages by running the following commands:
   
         pacman -Syu
            
   Close the terminal after the update is complete.
   
      Open MSYS2 UCRT64 Terminal:
      
      Reopen the MSYS2 UCRT64 terminal. This version of the terminal supports better compatibility with Windows.
   
   Step 2: Install GTK and Development Tools

   Install GTK:
   
      In the MSYS2 UCRT64 terminal, install GTK and its dependencies using the following command
           
         pacman -S mingw-w64-ucrt-x86_64-gtk3 mingw-w64-ucrt-x86_64-toolchain
            
      This will install GTK 3 and the necessary development tools like GCC.
      
      Verify Installation:
      
      You can verify the installation by running the following command to check the GTK version:
   
         pkg-config --modversion gtk+-3.0
         
      If the installation is successful, this command will output the version of GTK installed.
   
   Step 3: Configure Environment Variables (Optional)
   
      If you need to run the GTK-based application directly from the Windows command prompt (outside of MSYS2), you may need to add MSYS2's binary paths to your Windows environment variables.
      
      Add MSYS2 Paths to Environment Variables:
      
      Open the System Properties and navigate to Advanced > Environment Variables.
      
      Under System variables, find the Path variable, and click Edit.
      
      Add the following paths (replace C:\msys64 with your actual MSYS2 installation path):

   text
   
      C:\msys64\ucrt64\bin
      
      C:\msys64\usr\bin
      
   Click OK to save the changes.
   
      Test in Command Prompt:
      
      Open a new Command Prompt and type:
   
         gcc --version
      If installed correctly, the command will return the GCC version, confirming that MSYS2 and GTK are accessible globally.
      
      Step 4: Compile and Run GTK Programs
      
      You can now compile and run GTK applications using the MSYS2 UCRT64 terminal with the command:


         gcc -o your_program.exe your_source_file.c $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)
         ./your_program.exe

4. **Compile the project**
   
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

   
