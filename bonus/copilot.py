#!/usr/bin/env python3

from openai import OpenAI


def get_api_key(file_path):
    """Lit un fichier et extrait la valeur de KEY."""
    with open(file_path, "r") as file:
        line = file.readline().strip()
    if line.startswith("KEY=") and line.count('"') == 2:
        return line.split('"')[1]
    return None


file_path = "bonus/.env"
api_key = get_api_key(file_path)


client = OpenAI(api_key=api_key)

ask = ""

while (ask != "exit"):

    ask = input(">> ")

    response = client.responses.create(
        model="gpt-4.1",
        input=ask
    )

    print(response.output_text)
