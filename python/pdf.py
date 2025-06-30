import pdfplumber
import pandas as pd

pdf_path = "sample.pdf"
excel_path = "output_range.xlsx"

start_page = 8  # 1ページ目は 1
end_page = 10    # このページまで処理（含む）

combined_df = pd.DataFrame()

def make_unique_columns(columns):
    seen = {}
    result = []
    for col in columns:
        if col in seen:
            seen[col] += 1
            result.append(f"{col}_{seen[col]}")
        else:
            seen[col] = 0
            result.append(col)
    return result

with pdfplumber.open(pdf_path) as pdf:
    for i in range(start_page - 1, end_page):
        page = pdf.pages[i]
        table = page.extract_table()
        if table:
            columns = make_unique_columns(table[0])
            df = pd.DataFrame(table[1:], columns=columns)
            df.insert(0, "Page", i + 1)
            combined_df = pd.concat([combined_df, df], ignore_index=True)

# Excelに1シートで保存
combined_df.to_excel(excel_path, index=False)

print(f"{start_page}ページ目から{end_page}ページ目までを結合して保存しました: {excel_path}")
