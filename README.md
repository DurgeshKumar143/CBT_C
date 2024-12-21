# Computer Based Test (CBT) System

## 🎯 Introduction
Welcome to the Computer Based Test (CBT) System! This system is designed to allow users to take a mock test across various subjects and view their results instantly. It features user registration, login functionality, test-taking with multiple-choice questions, and marksheet generation.

## 📚 Features
- **User Registration & Login** 🔐
- **Subject Selection** 📚
- **Test-taking with Multiple-choice Questions** 💡
- **Marksheets & Results Generation** 📊
- **Review of Wrong Answers** ❌

## 🧑‍💻 How It Works
### 1. User Registration 🔄
New users can register by creating a username and password. A user can register a maximum of 10 accounts.

### 2. Login 🔑
After registration, users can log in using their credentials to access the test.

### 3. Subject Selection 🎓
Upon logging in, users can select a subject for the test from the following options:
- Mathematics ➗
- Physics ⚛️
- Chemistry 🧪
- Biology 🧬
- Computer Science 💻

### 4. Test-taking 📝
Each test consists of 10 multiple-choice questions.  
Each question has 4 options (A, B, C, D), and the user must select the correct one.  
There is no negative marking for incorrect answers. ✅❌

### 5. Results 📊
After completing the test:
- The system will display the total score out of 10.
- A marksheet will be generated with the user's performance, including a grade based on their score:
  - **A+**: 81% - 100%
  - **A**: 60% - 80%
  - **B**: 41% - 59%
  - **C**: 31% - 40%
  - **D**: 1% - 30% (Fail)

### 6. Reviewing Wrong Answers 🔍
After the test, users can opt to review the questions they answered incorrectly, providing them an opportunity to learn and improve.

## 🔧 Code Structure
### 1. User Structure
```c
typedef struct{
    char username[30];
    char password[6];
} User;

```struct Question {
    char question[500];
    char options[MAX_OPTIONS][50];
    char correctOption;
};```



## 🛠️ Functions Overview

### 1. User Registration (register_user)

Allows the user to create a new account with a username and password.

### 2. Login (login_user)
Validates the user credentials and allows access to the test if the login is successful.

### 3. Test Taking (takeTest)
Handles the selection of questions for a specific subject, collects answers, and calculates the total score.

### 4. Marksheets (generate_marksheet)
Generates a detailed marksheet with the user's score, percentage, and grade.

## 🚀 Test Instructions
1. **Start the Test**: Register and log in to begin.
2. **Choose a Subject**: Select one subject from the available options.
3. **Answer Questions**: Select the correct answer for each question. You can take your time—there is no time limit for the test. ⏳
4. **Submit**: Once all questions are answered, submit the test and view your results. 📈

## 🏆 Result Generation and Grading System
Based on the percentage score, the user will receive a grade:
- **A+** (81%-100%): Excellent! 🌟
- **A** (60%-80%): Good job! 👍
- **B** (41%-59%): Well done! 👏
- **C** (31%-40%): Needs improvement. 💪
- **D** (1%-30%): Better luck next time. 🤞

## 🔒 Security and Access Control
- The system ensures that each user has unique login credentials.
- Passwords are hidden during input for security purposes.
- All marksheets are digitally verified.

## 🌟 Additional Features
- **Review Incorrect Answers**: After completing the test, users can review the questions they answered incorrectly. This helps improve knowledge retention.
- **User-Friendly Interface**: Simple and clean user interface with clear instructions at every step.

## 📋 Conclusion
This CBT system provides a simple and efficient platform for users to practice and test their knowledge in various subjects. With features like user registration, login, test-taking, and result generation, it provides a comprehensive learning experience.

Good luck with your test-taking! 🍀

