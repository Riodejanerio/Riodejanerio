import streamlit as st
import numpy as np

def main():
    st.title("Beef Cattle Ration Calculator")
    st.markdown(
        """
        Example: <br>
        Body weight: 350 <br>
        Live weight gain: 0.7 kg <br>
        DM% of hay: 85 <br>
        Energy (MJ) present in per kg DM of hay: 8 MJ <br>
        DM% of concentrate: 88 <br>
        Energy (MJ) present in per kg DM of concentrate: 12 
        """, 
        unsafe_allow_html=True
    )

    bw = st.number_input("Enter body weight:", min_value=0.0, step=1.0)
    lwg = st.number_input("Enter desired live weight gain:", min_value=0.0, step=0.1)
    dmhay = st.number_input("Enter DM% of hay:", min_value=0.0, step=1.0)
    meh = st.number_input("Enter energy (MJ) present in per kg DM of hay:", min_value=0.0, step=1.0)
    dmconc = st.number_input("Enter DM% of concentrate:", min_value=0.0, step=1.0)
    mec = st.number_input("Enter energy (MJ) present in per kg DM of concentrate:", min_value=0.0, step=1.0)
    

    if st.button("Calculate Ration"):
        hay_val, conc_val = calculate_ration(bw, lwg, dmhay, meh, dmconc, mec)
        if hay_val is not None and conc_val is not None:
            st.write(f"Required Hay: {hay_val:.2f} kg, and Concentrate: {conc_val:.2f} kg for daily live weight gain of {lwg:.2f} kg.")
        else:
            st.write("No suitable ration found.")

def calculate_ega(bw, lwg):
    ega = (6.28 * lwg + 0.0188 * bw * lwg) / (1 - lwg * 0.3)
    return ega

def calculate_ration(bw, lwg, dmhay, meh, dmconc, mec):
    if bw <= 350 and lwg > 0.6:
        dmi = bw * 0.03
    elif 250 <= bw < 300 and lwg <= 0.6:
        dmi = bw * 0.030
    elif 350 < bw < 800:
        dmi = bw * 0.025
    elif 800 <= bw <= 1200:
        dmi = bw * 0.02
    elif bw > 300 and lwg > 0.9:
        dmi = bw * 0.040
    elif bw < 160 and lwg > 0.5:
        dmi = bw * 0.032
    else:
        dmi = bw * 0.015

    start_value = 0.6 * dmi
    end_value = 0.9 * dmi
    hay = []
    for value in np.arange(start_value * 100, end_value * 100 + 1, 1):
        hay.append(value / 100)

    start_value = 0.2 * dmi
    end_value = 0.3 * dmi
    conc = []
    for value in np.arange(start_value * 100, end_value * 100 + 1, 1):
        conc.append(value / 100)

    ega = calculate_ega(bw, lwg)

    for conc_val in conc:
        for hay_val in hay:
            dm = hay_val * (dmhay / 100) + conc_val * (dmconc / 100)
            mer = (hay_val * (dmhay / 100) * meh) + (conc_val * (dmconc / 100) * mec)
            Mm = 8.3 + 0.091 * bw
            MD = mer / dm
            MEP = mer - Mm
            Eg = MEP * 0.0414 * MD

            if abs(Eg - ega) < 0.1:  # Adjust tolerance as needed
                return hay_val, conc_val

    return None, None

if __name__ == "__main__":
    main()
