#include "TextRenderer.h"

TextRenderer::TextRenderer()
{
}

TextRenderer::~TextRenderer()
{
}

bool TextRenderer::DrawTextScreen(Text* text, Player* player, char typed_text, void *font)
{
	// Draw text
	//int w;
	//w = glutBitmapLength(GLUT_BITMAP_8_BY_13, text);

	if (typed_text == tolower(text->GetText()[text->GetMatchedText()]))
		text->IncreaseMatchedText();

	unsigned char test1[sizeof(text->GetText()) + 1] = "";
	std::string test = text->GetText();
	std::string sub_test = text->GetText().substr(0, text->GetMatchedText());
	unsigned char test2[sizeof(sub_test) + 1] = "";

	std::copy(test.begin(), test.end(), test1);
	std::copy(sub_test.begin(), sub_test.end(), test2);
	test1[sizeof(text->GetText())] = 0;
	test2[sizeof(sub_test)] = 0;

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(text->GetX(), text->GetY());
	for (int i = 0; i < strlen((char*)test1); i++)
	{
		glutBitmapCharacter(font, test1[i]);
	}

	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(text->GetX(), text->GetY());
	for (int i = 0; i < strlen((char*)test2); i++)
	{
		glutBitmapCharacter(font, test2[i]);
	}

	if (text->GetMatchedText() == text->GetText().length()) {
		int ind = rand() % vocab.size();
		text->ResetString(vocab[ind]);
		text->ResetPos();
		return true;
	}

	return false;
}

bool TextRenderer::DrawStaticText(Text * text, void *font)
{
	unsigned char test1[sizeof(text->GetText()) + 1] = "";
	std::string test = text->GetText();

	std::copy(test.begin(), test.end(), test1);
	test1[sizeof(text->GetText())] = 0;

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(text->GetX(), text->GetY());
	for (int i = 0; i < strlen((char*)test1); i++)
	{
		glutBitmapCharacter(font, test1[i]);
	}

	return false;
}
