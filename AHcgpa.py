import streamlit as st

def grade():
    present_cgpa = st.number_input("Enter your present CGPA:", value=None)
    target_cgpa = st.number_input("Enter your targeted CGPA:", value=None)
    if target_cgpa is not None and target_cgpa > 4:
        st.write("Targeted CGPA cannot be greater than 4.")
        return
    Number_of_semester_passed = st.number_input("Number of semester passed to obtain present CGPA:", value=None, step=1)

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

    total_credit = 192
    
    target_grade = target_cgpa * total_credit
    present_grade = present_cgpa * total_earned_credit
    required_grade = target_grade - present_grade
    required_cgpa = required_grade / (total_credit - total_earned_credit)

    if required_cgpa > 4:
        st.write("You are not able to gain the targeted CGPA. Better luck next time.")
    else:
        st.write(f"You have to obtain {required_cgpa:.3f} CGPA per rest of the semester")

def main():
    st.title("Required CGPA Calculator for Animal Husbandry Faculty")

if __name__ == "__main__":
    main()
