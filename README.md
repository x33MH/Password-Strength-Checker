# Password-Strength-Checker

This project is a Password Strength Checker built using GTK in C. It evaluates the strength of passwords and offers suggestions to improve them.

## Table of Contents
  1. [Installation and Set up](#installation-and-setup)
  2. [Features](#features)
  3. [Contributing](#contributing)
  4. [License](#license)
  5. [Acknowledgements](#acknowledgements)

## Installation and Setup

1. ### **Clone the repository:**

   Clone code and change directory 
   
   ```bash
      git clone https://github.com/x33MH/Password-Strength-Checker.git
   
      cd password-checker

3. ### **Install dependencies:**
   
   Here’s how you can install GTK on Windows:
   
   _Step 1: Install MSYS2_
   
   - MSYS2 is a software distribution and building platform for Windows that provides a Unix-like environment and package management system.
   
   Download MSYS2:
   
   - Visit the MSYS2 website and download the installer.
   
   - Run the installer and follow the prompts to install MSYS2. Choose a directory where MSYS2 will be installed (e.g., C:\msys64).
      
   Update the Package Database:
   
   - After installation, open the MSYS2 terminal (MSYS2 UCRT64 is recommended).
   
   Update the package database and core system packages by running the following commands:
   
         pacman -Syu
            
   Close the terminal after the update is complete.
   
      - Open MSYS2 UCRT64 Terminal:
      
      - Reopen the MSYS2 UCRT64 terminal. This version of the terminal supports better compatibility with Windows.
   
   _**Step 2: Install GTK and Development Tools**_
   Install GTK:
   
      In the MSYS2 UCRT64 terminal, install GTK and its dependencies using the following command
           
         pacman -S mingw-w64-ucrt-x86_64-gtk3 mingw-w64-ucrt-x86_64-toolchain
            
      This will install GTK 3 and the necessary development tools like GCC.
      
      Verify Installation:
      
      You can verify the installation by running the following command to check the GTK version:
   
         pkg-config --modversion gtk+-3.0
         
      If the installation is successful, this command will output the version of GTK installed.
   
   _**Step 3: Configure Environment Variables (Optional)**_
   
      If you need to run the GTK-based application directly from the Windows command prompt (outside of MSYS2), you may need to add MSYS2's binary paths to your Windows environment variables.
      
      Add MSYS2 Paths to Environment Variables:
      
      - Open the System Properties and navigate to Advanced > Environment Variables.
      
      - Under System variables, find the Path variable, and click Edit.
      
      - Add the following paths (replace C:\msys64 with your actual MSYS2 installation path):

   Example
   
         C:\msys64\ucrt64\bin
         
         C:\msys64\usr\bin
      
      - Click OK to save the changes.
   
      - Test in Command Prompt:
      
      - Open a new Command Prompt and type:
   
         gcc --version
   
      If installed correctly, the command will return the GCC version, confirming that MSYS2 and GTK are accessible globally.
      
      _**Step 4: Compile and Run GTK Programs**_
      
      You can now compile and run GTK applications using the MSYS2 UCRT64 terminal with the command:

         gcc -o your_program.exe your_source_file.c $(pkg-config --cflags gtk+-3.0) $(pkg-config --libs gtk+-3.0)
         ./your_program.exe   

## Features
   
   - Real-time password strength evaluation
         
   - Suggestions to improve password strength
         
   - Toggle password visibility
   
## Contributing

Contributions are welcome! Please follow these steps to contribute:

  1. Fork the Project
  2. Create your Feature Branch
  ```
    git checkout -b feature-branch
  ```
  3. Commit your Changes
  ```
    git commit -m 'Add some feature
  ```
  4. Push to the Branch
  ```
    git push origin feature-branch
  ```
  5. Open a Pull Request

## License

   This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements
  - **Contributors** <br>
  => Project Manager:  <br>
  => Contributor :  <br>
  => Contributor :  <br>
  => Contributor :  <br>
  => Contributor :  <br>

  - **C/C++ Programming Language** <br>
    This project utilizes C/C++ for its core functionality. Special thanks to the C and C++ communities for their robust programming languages and support.   
