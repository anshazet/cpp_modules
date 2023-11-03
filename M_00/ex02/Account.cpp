/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:50:41 by ashalagi          #+#    #+#             */
/*   Updated: 2023/09/20 13:01:12 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor for the Account class
Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),   // Initialize account index
    _amount(initial_deposit),     // Initialize account balance with the initial deposit
    _nbDeposits(0),               // Initialize the number of deposits to 0
    _nbWithdrawals(0) {           // Initialize the number of withdrawals to 0
    _nbAccounts++;                // Increment the total number of accounts
    _totalAmount += initial_deposit;  // Update the total amount in all accounts
    _displayTimestamp();          // Display a timestamp (to be implemented)
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor for the Account class
Account::~Account(void)
{
    _nbAccounts--;                // Decrement the total number of accounts
    _totalAmount -= _amount;      // Subtract the account balance from the total amount
    _totalNbDeposits += _nbDeposits;  // Add the number of deposits to the total
    _totalNbWithdrawals += _nbWithdrawals;  // Add the number of withdrawals to the total
    _displayTimestamp();          // Display a timestamp (to be implemented)
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Static method to get the total number of accounts
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

// Static method to get the total amount in all accounts
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

// Static method to get the total number of deposits made
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

// Static method to get the total number of withdrawals made
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

// Static method to display information about all accounts
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();  // Display a timestamp (to be implemented)
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Method to make a deposit into the account
void Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        _nbDeposits++;  // Increment the number of deposits for this account
        _totalNbDeposits++;  // Increment the total number of deposits
        _amount += deposit;  // Add the deposit amount to the account balance
        _totalAmount += deposit;  // Add the deposit amount to the total balance
        _displayTimestamp();  // Display a timestamp (to be implemented)
        std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit)
                  << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

// Method to make a withdrawal from the account
bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount >= withdrawal)
    {
        _nbWithdrawals++;  // Increment the number of withdrawals for this account
        _totalNbWithdrawals++;  // Increment the total number of withdrawals
        _amount -= withdrawal;  // Subtract the withdrawal amount from the account balance
        _totalAmount -= withdrawal;  // Subtract the withdrawal amount from the total balance
        _displayTimestamp();  // Display a timestamp (to be implemented)
        std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal)
                  << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;  // Withdrawal successful
    }
    else
    {
        _displayTimestamp();  // Display a timestamp (to be implemented)
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;  // Withdrawal refused (insufficient balance)
    }
}

// Method to check the current balance of the account
int Account::checkAmount(void) const
{
    return _amount;
}

// Method to display the status of the account
void Account::displayStatus(void) const
{
    _displayTimestamp();  // Display a timestamp (to be implemented)
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Private method to display a timestamp (to be implemented)
void Account::_displayTimestamp(void)
{
    // This method should be implemented to display a timestamp
    // You can use appropriate libraries to generate timestamps as needed
}

/*
The code recreates the Account class by implementing its constructor, destructor,
static methods, and member methods to perform deposit and withdrawal operations
while maintaining account statistics. Additionally, it includes placeholders for
timestamp-related functionality that you would need to implement separately based
on your requirements.

Please note that the _displayTimestamp function is a placeholder for displaying
timestamps, and you would need to implement it using appropriate libraries or methods
to generate timestamps as per your desired format.
*/