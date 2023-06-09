/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:32:52 by hania             #+#    #+#             */
/*   Updated: 2023/04/30 09:14:20 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

int main() {
  Bureaucrat mark("Mark", 1);
  std::cout << mark;

  Form form("Immigration Form", 1, 15);
  std::cout << form;

  std::cout << "Is the form signed? " << form.sendStatus() << std::endl;

  // Try to sign the form with a bureaucrat high enough
  mark.signForm(form);

  // Check the form's status again. Should be signed
  std::cout << "Is the form signed? " << form.sendStatus() << std::endl;

  // Try to sign the form with a bureaucrat with a low grade.
  Bureaucrat sophia("Sophia", 15);
  try {
    sophia.signForm(form);
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  // Check the form's status again.
  std::cout << "Is the form signed? " << form.sendStatus() << std::endl;
  return 0;
}