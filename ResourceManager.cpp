#include "ResourceManager.h"

void ResourceManager::setFont(std::string fontKey, std::string fontName)
{

    // Check if the font with the same key already exists
    auto it = this->fonts.find(fontKey);
    if (it != this->fonts.end()) {
        std::cerr << "Font with key '" << fontKey << "' already exists.\n";
        return;
    }

    //Add a new font in our Fonts map
    sf::Font* aux_font = new sf::Font();
    if (aux_font->loadFromFile(fontName)) {
        this->fonts[fontKey] = aux_font;
    }
    else {
        //deallocate dynamic memory
        std::cerr << "Error Loading Font: '" << fontName << "'\n";
        delete aux_font;
    }

}

void ResourceManager::setTexture(std::string categoryKey, std::string textureKey, std::string texture)
{
    //Check if the texture/spritesheet with the same key already exists 
    auto it = this->textures[categoryKey].find(textureKey);
    if (it != this->textures[categoryKey].end()) {
        std::cerr << "Texture with key '" << textureKey << "' already exists.\n";
        return;
    }

    //Add a new texture(and a category if it isn't in the map already)
    sf::Texture* aux_texture = new sf::Texture();
    if (aux_texture->loadFromFile(texture)) {
        this->textures[categoryKey][textureKey] = aux_texture;
    }
    else {
        //Deallocate dynamic memory
        std::cerr << "Error loading Texture: '" << texture << "\n";
        delete aux_texture;
    }


}


void ResourceManager::initTextures()
{
    this->setTexture("Background", "Title", "Resources/Images/Backgrounds/Title/background.png");
    std::cout << "TEXTURES INITIALIZED IN RESOURCEMANAGER\n";
}

void ResourceManager::initFonts()
{
    this->setFont("Gen1_2", "Resources/Fonts/1-2_Gen_Font.ttf");
    this->setFont("Gen3", "Resources/Fonts/3_Gen_Font.ttf");
    this->setFont("Gen4", "Resources/Fonts/4_Gen_Font.ttf");
    this->setFont("Gen5", "Resources/Fonts/5_Gen_Font.ttf");
    this->setFont("Gen6", "Resources/Fonts/6_Gen_Font.ttf");
    std::cout << "FONTS INITIALIZED IN RESOURCEMANAGER\n";
    this->getSize();
}

ResourceManager::ResourceManager()
{
    this->initTextures();
    this->initFonts();
}

ResourceManager::~ResourceManager()
{
    // Deallocate memory for textures
    for (auto& category : this->textures) {
        for (auto& texturePair : category.second) {
            delete texturePair.second;
        }
    }

    // Deallocate memory for fonts
    for (auto& fontPair : this->fonts) {
        delete fontPair.second;
    }

    std::cout << "ResourceManager destructor called." << std::endl;
}

sf::Texture* ResourceManager::getTexture(const std::string& categoryKey, const std::string& textureKey)
{
    // Check if the category exists
    auto categoryIt = this->textures.find(categoryKey);
    if (categoryIt != this->textures.end())
    {
        // Check if the texture exists in the category
        auto textureIt = categoryIt->second.find(textureKey);
        if (textureIt != categoryIt->second.end())
        {
            // Return the texture pointer
            return textureIt->second;
        }
    }

    // Return nullptr if the category or texture is not found
    return nullptr;
}


sf::Font* ResourceManager::getFont(const std::string& fontKey)
{
    auto it = this->fonts.find(fontKey);
    if (it != this->fonts.end()) {
        return it->second; // Return the pointer to font if found
    }
    return nullptr; // returns nullptr if the fond doesnt exists
}

void ResourceManager::getAvailableFonts()
{
    //Prints the different available fonts
    for (auto it : this->fonts) {
        std::cout << it.second;
    }
}



