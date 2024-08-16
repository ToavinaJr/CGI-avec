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

    std::cout << "Content-Type: text/html\n\n";
    if (nom == validNom && mdp == validMpd) {
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
        std::cout << "<!DOCTYPE html>\n";
        std::cout << "<html lang=\"en\">\n";
        std::cout << "<head>\n";
        std::cout << "    <meta charset=\"UTF-8\">\n";
        std::cout << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        std::cout << "    <title>Formulaire d'inscription</title>\n";
        std::cout << "    <style>\n";
        std::cout << "        body {\n";
        std::cout << "            font-family: Arial, sans-serif;\n";
        std::cout << "            background-color: #f4f4f4;\n";
        std::cout << "            display: flex;\n";
        std::cout << "            justify-content: center;\n";
        std::cout << "            align-items: center;\n";
        std::cout << "            height: 100vh;\n";
        std::cout << "            margin: 0;\n";
        std::cout << "        }\n";
        std::cout << "        \n";
        std::cout << "        .container {\n";
        std::cout << "            background-color: white;\n";
        std::cout << "            padding: 20px 30px;\n";
        std::cout << "            border-radius: 10px;\n";
        std::cout << "            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);\n";
        std::cout << "            max-width: 400px;\n";
        std::cout << "            width: 100%;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .container h2 {\n";
        std::cout << "            text-align: center;\n";
        std::cout << "            margin-bottom: 20px;\n";
        std::cout << "            color: #333;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group {\n";
        std::cout << "            margin-bottom: 15px;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group label {\n";
        std::cout << "            display: block;\n";
        std::cout << "            margin-bottom: 5px;\n";
        std::cout << "            color: #555;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group input {\n";
        std::cout << "            width: 100%;\n";
        std::cout << "            padding: 10px;\n";
        std::cout << "            border: 1px solid #ccc;\n";
        std::cout << "            border-radius: 5px;\n";
        std::cout << "            box-sizing: border-box;\n";
        std::cout << "            font-size: 16px;\n";
        std::cout << "            color: #333;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group input:focus {\n";
        std::cout << "            border-color: #007bff;\n";
        std::cout << "            outline: none;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group input[type=\"submit\"] {\n";
        std::cout << "            background-color: #007bff;\n";
        std::cout << "            color: white;\n";
        std::cout << "            border: none;\n";
        std::cout << "            cursor: pointer;\n";
        std::cout << "            font-weight: bold;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        .form-group input[type=\"submit\"]:hover {\n";
        std::cout << "            background-color: #0056b3;\n";
        std::cout << "        }\n";
        std::cout << "\n";
        std::cout << "        \n";
        std::cout << "    </style>\n";
        std::cout << "</head>\n";
        std::cout << "<body>\n";
        std::cout << "\n";
        std::cout << "<div class=\"container\">\n";
        std::cout << "    <h2>Inscription</h2>\n";
        std::cout << "    <form action=\"index.cgi\" method=\"GET\">\n";
        std::cout << "        <div class=\"form-group\">\n";
        std::cout << "            <label for=\"name\">Nom :</label>\n";
        std::cout << "            <input type=\"text\" id=\"name\" name=\"name\" required>\n";
        std::cout << "        </div>\n";
        std::cout << "        <div class=\"form-group\">\n";
        std::cout << "            <label for=\"password\">Mot de passe :</label>\n";
        std::cout << "            <input type=\"password\" id=\"password\" name=\"password\" required>\n";
        std::cout << "        </div>\n";
        std::cout << "        <div class=\"form-group\">\n";
        std::cout << "            <input type=\"submit\" value=\"Se Connecter\">\n";
        std::cout << "        </div>\n";
        std::cout << "    </form>\n";
        std::cout << "    \n";
        std::cout << "</div>\n";
        std::cout << "\n";
        std::cout << "</body>\n";
        std::cout << "</html>\n";
    }

    return EXIT_SUCCESS;
}