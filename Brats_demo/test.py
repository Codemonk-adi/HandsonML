from fileinput import filename
import pandas as pd
import os
filename = 'batch_name.csv'
df = pd.DataFrame(columns=['PATIENT_ID','Images','Modalities','ROIFile','SELECTED_ROI','ROI_LABEL'])
list_dir = next(os.walk('.'))[1]
for dir in list_dir:
    img_l = os.listdir(dir)
    img_list = [os.path.abspath(os.path.join(".",dir,i)) for i in img_l]
    mask  = img_list[1]
    del img_list[1]
    image_str = ''
    for img in img_list:
        image_str+=f"{img}|"
    image_str = image_str[:-1]
    df = df.append({'PATIENT_ID':dir[-5:],'Images':image_str,'Modalities':'FLAIR|T1|T1Gd|T2','ROIFile':mask,'SELECTED_ROI':1,'ROI_LABEL':"ED"},ignore_index=True)

df.to_csv(filename,index=False)