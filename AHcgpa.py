import streamlit as st

def grade(present_cgpa, target_cgpa, Number_of_semester_passed):
    if target_cgpa > 4:
        st.write("Targeted CGPA cannot be greater than 4.")
        return

    # Map the number of semesters to the total earned credit
    if Number_of_semester_passed == 1:
        total_earned_credit = 20
    elif Number_of_semester_passed == 2:
        total_earned_credit = 43
    elif Number_of_semester_passed == 3:
        total_earned_credit = 67
    elif Number_of_semester_passed == 4:
        total_earned_credit = 89
    elif Number_of_semester_passed == 5:
        total_earned_credit = 112
    elif Number_of_semester_passed == 6:
        total_earned_credit = 134
    elif Number_of_semester_passed == 7:
        total_earned_credit = 157
    elif Number_of_semester_passed == 8:
        total_earned_credit = 180
    else:
        st.write("Invalid number of semesters.")
        return

    total_credit = 192

    target_grade = target_cgpa * total_credit
    present_grade = present_cgpa * total_earned_credit
    required_grade = target_grade - present_grade
    required_cgpa = required_grade / (total_credit - total_earned_credit)

    if required_cgpa > 4:
        st.write("You are not eligible to get the targeted CGPA")
    else:
        st.write(f"You have to obtain {required_cgpa:.3f} CGPA per rest of the semesters")

def main():
    st.title("Required CGPA Calculator for Animal Husbandry Faculty")
    st.markdown("""
        For example, after 2 semesters your CGPA is 3.40 and your targeted CGPA is 3.60, 
        thus you have to maintain at least 3.658 for the rest of the semesters.
    """)

    present_cgpa = st.number_input("Enter your present CGPA:")
    target_cgpa = st.number_input("Enter your targeted CGPA:")
    Number_of_semester_passed = st.number_input("Number of semesters passed to obtain present CGPA:", step=1)

    if st.button("Calculate"):
        if present_cgpa and target_cgpa and Number_of_semester_passed:
            grade(present_cgpa, target_cgpa, Number_of_semester_passed)
        else:
            st.write("Please fill in all input fields.")

    st.write("")
    st.write("")
    st.markdown("<b style='font-family: Roboto;'>Developed by AH-55th Batch of BAU</b>", unsafe_allow_html=True)

if __name__ == "__main__":
    main()
