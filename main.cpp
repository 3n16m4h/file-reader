int main()
{
std::string file_name;
std::cout << "Inserisci il nome del file da leggere: ";
std::cin >> file_name;

c

std::ifstream file(file_name);

if (!file)
{
    std::cout << "Impossibile aprire il file " << file_name << std::endl;
    return 1;
}

std::ofstream temp("temp.txt");

std::string line;
while (std::getline(file, line))
{
    if (line.find("SUCCESS") != std::string::npos)
    {
        temp << line << std::endl;
    }
}

file.close();
temp.close();

if (remove(file_name.c_str()) != 0)
{
    std::cout << "Impossibile rimuovere il file originale" << std::endl;
    return 1;
}

if (rename("temp.txt", file_name.c_str()) != 0)
{
    std::cout << "Impossibile rinominare il file temporaneo" << std::endl;
    return 1;
}

std::cout << "Le righe contenenti la parola 'SUCCESS' sono state salvate nel file " << file_name << std::endl;

return 0;

}
