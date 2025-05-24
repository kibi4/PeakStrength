/**
 * @file loginscreen.h
 * @brief Header file for LoginScreen Class
 * This has the declaration of the LoginScreen and provides the interface of it

 * @author Alexander Vong and Kibi Paskaran
*/

#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include <QWidget>

class QLineEdit;
class QPushButton;

/**
 * @class LoginScreen
 * @brief Represents the login screen GUI.*
 * Class provides a simple login interface with username and password fields, and has buttons for logging in and creating an account.
*/

class LoginScreen : public QWidget {
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);


signals:
/**
 * @brief When a user successfully logs in.
*/
    void loginSuccess();

/**     
 * @brief When a user chooses to create an account.
*/
    void createAccount();

private slots:
/**
 * @brief Handles the login attempt.
 * This function checks the provided username and password
 * It will show loginSuccess() if the credentials are valid.
*/
    void handleLogin();

/**
 * @brief Handles the account creation 
*/
    void handleCreateAccount();

private:
    QLineEdit *usernameInput;//Input Field for username
    QLineEdit *passwordInput;//Input Field for password
};

#endif
