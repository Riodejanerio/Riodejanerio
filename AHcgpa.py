def grade():
    present_cgpa = float(input("Enter your present CGPA: "))
    target_cgpa = float(input("Enter your targeted CGPA: "))
    if target_cgpa > 4:
        return
    Number_of_semester_passed = float(input("Number of semester passed to obtain present cgpa: "))

    if Number_of_semester_passed == 1:
      total_earned_credit = 20
    if Number_of_semester_passed == 2:
      total_earned_credit = 43
    if Number_of_semester_passed == 3:
      total_earned_credit = 67
    if Number_of_semester_passed == 4:
      total_earned_credit = 89
    if Number_of_semester_passed == 5:
      total_earned_credit = 112
    if Number_of_semester_passed == 6:
      total_earned_credit = 134
    if Number_of_semester_passed == 7:
      total_earned_credit = 157
    if Number_of_semester_passed == 8:
      total_earned_credit = 180

    #total_earned_credit = float(input("Enter your total earned credit till now: "))
    total_credit = 192
    
    target_grade = target_cgpa * total_credit
    present_grade = present_cgpa * total_earned_credit
    required_grade = target_grade - present_grade
    required_cgpa = required_grade / (total_credit - total_earned_credit)

    if required_cgpa > 4:
        print("You are not able to gain the targeted CGPA. Better luck next time.")
    else:
        print(f"You have to obtain {required_cgpa:.3f} CGPA per rest of the semester")
grade()