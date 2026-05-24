<!-- Improved compatibility of back to top link -->
<a id="readme-top"></a>




<!-- PROJECT LOGO -->
<br />
<div align="center">

<h3 align="center">ELIZA Chatbot C</h3>

  <p align="center">
    A terminal-based chatbot inspired by the classic ELIZA program written in C.
    <br />
    Developed for the Programming course of the LEEC degree at Instituto Superior Técnico.
    <br />
    <br />
    <a href="https://github.com/itzhrqz/chatbot-eliza-c"><strong>Explore the project »</strong></a>
    <br />
    <br />
    <a href="https://github.com/itzhrqz/chatbot-eliza-c/issues">Report Bug</a>
    &middot;
    <a href="https://github.com/itzhrqz/chatbot-eliza-c/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#compilation">Compilation</a></li>
        <li><a href="#running-the-program">Running the Program</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#project-context">Project Context</a></li>
    <li><a href="#contributors">Contributors</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This repository contains a chatbot inspired by the classic ELIZA program, one of the earliest natural language processing systems.

The chatbot uses pattern matching and keyword recognition techniques to simulate conversations with the user through a terminal interface.

Features included in the project:
* Interactive command-line interface
* Keyword-based response generation
* Rule-based conversational logic
* Modular C code structure

The project was developed with a focus on practicing fundamental programming concepts such as:
* Dynamic memory management
* String manipulation
* Modular software design
* File organization and compilation workflows

<p align="right">(<a href="#readme-top">back to top</a>)</p>


### Built With

* C90
* GCC
* Makefile

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Compilation

Using GCC:
```sh
gcc *.c -o eliza
```

Or using the Makefile:
```sh
make
```

### Running the Program

```sh
./eliza
```

### Arguments
Mostra esta ajuda e termina // Shows this help and exits
```sh
-h            
```
Ficheiro com base de dados de respostas (por omissao: eliza.dat) // Sets the question/answer database, uses eliza.dat by default
```sh
  -f filename   
```
Ficheiro de entrada (por omissao: stdin) // Sets input file, by default uses stdin
```sh
  -i filename   
```
Ficheiro de saida (por omissao: stdout) // Sets output file, by default uses stdout
```sh  
  -o filename   
```
Ficheiro de log do input e output // Sets the log file for input/output
```sh  
  -l filename   
```
Usar regras de portugues em vez de ingles // Uses portuguese conjugation rules
```sh  
  -p            
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

After launching the program, the chatbot will prompt the user for input through the terminal.

Example interaction:

```text
ELIZA: HI!  I'M ELIZA.  LET'S TALK.  TYPE `BYE' TO END THIS SESSION.
You: Hi

ELIZA: HOW DO YOU DO. PLEASE STATE YOUR PROBLEM.
You: Why are you screaming ?

ELIZA: WHY ARE YOU INTERESTED IN WHETHER OR NOT I AM SCREAMING?
You: I am scared
...
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- PROJECT CONTEXT -->
## Project Context

This project was developed for the Programming course of the Electrical and Computer Engineering degree (LEEC) at Instituto Superior Técnico during the 2025/2026 academic year.

The objective of the assignment was to implement a chatbot similar to the original ELIZA system while applying the programming concepts taught throughout the course.

The source code contains informal comments and internal jokes written during development.
These do not affect functionality and were kept to preserve the development process and collaboration context.

Due to the academic nature of this project, all comments are written in Portuguese

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTORS -->
## Contributors

Developed collaboratively by:

* Henrique Carvalho ([@itzhrqz](https://github.com/itzhrqz))
* Diogo Reis        ([@x-dgR-x](https://github.com/x-dgR-x))

<!-- Optional GitHub profile links -->
<!-- * [Your Name](https://github.com/your_username) -->
<!-- * [Friend Name](https://github.com/friend_username) -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

This project was developed for academic purposes as part of a university course and is not intended for reuse, distribution, or modification.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
