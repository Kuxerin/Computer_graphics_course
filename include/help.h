#ifndef HELP_H
#define HELP_H

typedef enum {
	NO_HELP = -911, 
	HELP = 911, 
} ShownHelp;

void toggleHelp( int key, ShownHelp* shownHelp );
void renderHelp(Texture shownHelpTexture);

#endif /* HELP_H */