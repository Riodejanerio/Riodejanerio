import streamlit as st
import numpy as np

def calculate_ega(bw, lwg):
    ega = (6.28 * lwg + 0.0188 * bw * lwg) / (1 - lwg * 0.3)
    return ega

def calculate_ration(bw, lwg):
    if bw <= 350:
        dmi = bw * 0.03
    elif 350 < bw < 800:
        dmi = bw * 0.025
    elif 800 <= bw <= 1200:
        dmi = bw * 0.02
    else:
        dmi = bw * 0.015

    start_value = 0.6 * dmi
    end_value = 0.9 * dmi
    hay = []
    for value in np.arange(start_value * 100, end_value * 100 + 1, 1):
        hay.append(value / 100)
    dmhay = 85

    start_value = 0.2 * dmi
    end_value = 0.3 * dmi
    conc = []
    for value in np.arange(start_value * 100, end_value * 100 + 1, 1):
        conc.append(value / 100)
    dmconc = 88

    ega = calculate_ega(bw, lwg)

    for hay_val in hay:
        for conc_val in conc:
            dm = hay_val * (dmhay / 100) + conc_val * (dmconc / 100)
            mer = (hay_val * (dmhay / 100) * 8) + (conc_val * (dmconc / 100) * 12.5)
            Mm = 8.3 + 0.091 * bw
            MD = mer / dm
            MEP = mer - Mm
            Eg = MEP * 0.0414 * MD

            if abs(Eg - ega) < 0.1:  # Adjust tolerance as needed
                return hay_val, conc_val

def main():
    st.title("Beef Cattle Ration Calculator")
     """The Hay used here contains 85% dry matter and 8 MJ energy/Kg DM
                                    and 
    the Concentrate contains 88% dry matter and 12.5 MJ/Kg DM"""


    bw = st.number_input("Enter body weight:", min_value=0.0, step=1.0)
    lwg = st.number_input("Enter live weight gain:", min_value=0.0, step=0.1)

    if st.button("Calculate Ration"):
        hay_val, conc_val = calculate_ration(bw, lwg)
        st.write(f"Required Hay: {hay_val:.2f} kg, and Concentrate: {conc_val:.2f} kg for daily live weight gain of {lwg:.2f} kg.")

if __name__ == "__main__":
    main()
