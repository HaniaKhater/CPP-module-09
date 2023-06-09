/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:15:06 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 09:14:06 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form( const std::string name, const int toSign, const int toExec) 
    : _name(name)
    , _isSigned(false)
    , _gradeSign(toSign)
    , _gradeExec(toExec)
{
    if (toSign > 150 || toExec > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if (toSign < 1 || toExec < 1)
        throw(Bureaucrat::GradeTooHighException());
    std::cout << "Constructor has been called" << std::endl;
}

Form::Form() 
    : _name("28C")
    , _isSigned(false)
    , _gradeSign(70)
    , _gradeExec(25) 
{
    std::cout << "default constructor has been called" << std::endl;
}

Form::Form( const Form &ref ) 
    : _name(ref._name)
    , _isSigned(ref._isSigned)
    , _gradeSign(ref._gradeSign)
    , _gradeExec(ref._gradeExec)
{
    std::cout << "Copy constructor has been called" << std::endl;
}

Form::~Form() {
    std::cout << "Destructor has been called" << std::endl;
}

Form&   Form::operator=( const Form &rhs ) {
    _isSigned = rhs._isSigned;
    return *this;
}

std::string Form::getName() const {
    return _name;
}

int     Form::getGradeSign() const {
    return _gradeSign;
}

int     Form::getGradeExec() const {
    return _gradeExec;
}

bool    Form::getStatus() const {
    return _isSigned;
}

std::string    Form::sendStatus() const {
    if (_isSigned)
        return "Signed";
    return "Not Signed";
}

void    Form::beSigned( const Bureaucrat &bu ) {
    if ( bu.getGrade() <= _gradeSign )
        _isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & out, const Form &in) {
  return out << "Form Name:                 " << in.getName() << std::endl
	    << "Grade Required To Sign:    " << in.getGradeSign() << std::endl
	    << "Grade Required to Execute: " << in.getGradeExec() << std::endl
	    << "Signature Status:          " << in.sendStatus() << std::endl;
}