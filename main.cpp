#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

std::string extraireValeur(const std::string& chaine, const std::string& cle) {
    std::size_t debut = chaine.find(cle + "=");
    if (debut == std::string::npos) {
        return "";
    }
    debut += cle.length() + 1; // Position après le signe "="
    std::size_t fin = chaine.find("&", debut);
    return chaine.substr(debut, fin == std::string::npos ? fin : fin - debut);
}

int main() {
    std::string data = getenv("QUERY_STRING");
    
    std::string nom = extraireValeur(data, "name"), mdp = extraireValeur(data, "password");
    std::string validNom, validMpd;

    std::ifstream file("/var/www/ToavinaSylvianno.com/public_html/base.txt");

    file >>validNom;
    file >> validMpd;

    if (nom == validNom && mdp == validMpd) {

    
    std::cout << "Content-Type: text/html\n\n";
    std::cout << "<!DOCTYPE html>"
    <<"<html lang=\"en\">"
    <<"<head>"
    <<"    <meta charset=\"UTF-8\">"
    <<"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    <<"    <title>Page de Salutation</title>"
    <<"    <style>"
    <<"        body {"
    <<"            margin: 0;"
    <<"            padding: 0;"
    <<"            font-family: 'Arial', sans-serif;"
    <<"            background: linear-gradient(135deg, #71b7e6, #9b59b6);"
    <<"            height: 100vh;"
    <<"            display: flex;"
    <<"            justify-content: center;"
    <<"            align-items: center;"
    <<"            color: white;"
    <<"            text-align: center;"
    <<"        }"
    <<""
    <<"        .greeting-container {"
    <<"            background-color: rgba(0, 0, 0, 0.5);"
    <<"            padding: 40px;"
    <<"            border-radius: 10px;"
    <<"            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);"
    <<"        }"
    <<""
    <<"        .greeting-container h1 {"
    <<"            font-size: 3em;"
    <<"            margin-bottom: 10px;"
    <<"        }"
    <<""
    <<"        .greeting-container p {"
    <<"            font-size: 1.2em;"
    <<"            margin-bottom: 20px;"
    <<"        }"
    <<""
    <<"        .greeting-container a {"
    <<"            display: inline-block;"
    <<"            background-color: #3498db;"
    <<"            color: white;"
    <<"            text-decoration: none;"
    <<"            padding: 10px 20px;"
    <<"            border-radius: 5px;"
    <<"            transition: background-color 0.3s ease;"
    <<"        }"
    <<""
    <<"        .greeting-container a:hover {"
    <<"            background-color: #2980b9;"
    <<"        }"
    <<"    </style>"
    <<"</head>"
    <<"<body>"
    <<""
    <<"<div class=\"greeting-container\">"
    <<"    <h1>Bienvenue !</h1>"
    <<"    <p>Nous sommes ravis de vous voir ici. Explorez notre site pour découvrir plus de contenu.</p>"
    <<"    <div>"<<nom<<"</div>"
    <<"</div>"
    <<"</body>"
    <<"</html>";
    }
    else {
        std::cout << "Location: /";
    }

    return EXIT_SUCCESS;
}