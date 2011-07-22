/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <sys/reboot.h>

#include "themes.h"
#include "settings_file.h"
#include "extra-functions.h"

#define THEME_REBOOT_RECOVERY 0
#define TW_THEME	1
#define CM_THEME	2
#define RED_THEME	3
#define GOOGLE_THEME	4
#define JF_THEME	5
#define THEMES_BACK	6

char* checkTheme(int tw_theme)
{
	int isVal;
	int isTrue = 0;
	char* tmp_set = (char*)malloc(40);
	switch (tw_theme)
	{
		case TW_THEME:
			strcpy(tmp_set, "[ ] Team Win Theme (Default)");
			break;
		case CM_THEME:
			strcpy(tmp_set, "[ ] CyanogenMod Theme");
			break;
		case RED_THEME:
			strcpy(tmp_set, "[ ] Red Rum Theme");
			break;
		case GOOGLE_THEME:
			strcpy(tmp_set, "[ ] Google Theme");
			break;
		case JF_THEME:
			strcpy(tmp_set, "[ ] JesusFreke Theme (oldschool)");
			break;
	}
	sscanf(tw_color_theme_val,"%d",&isVal);
	if (isVal == tw_theme - 1)
	{
		tmp_set[1] = 'x';
	}
	return tmp_set;
}

void twrp_themes_menu()
{
    static char* MENU_THEMES_HEADERS[] = { "twrp Theme Chooser",
    								   	   "Taste tEh Rainbow:",
                                           NULL };
    
	char* MENU_THEMES[] =       { 	"[REBOOT AND APPLY THEME]",
									checkTheme(TW_THEME),
									checkTheme(CM_THEME),
									checkTheme(RED_THEME),
									checkTheme(GOOGLE_THEME),
									checkTheme(JF_THEME),
									"<-- Back To twrp Settings",
									NULL };

    char** headers = prepend_title(MENU_THEMES_HEADERS);
    
    inc_menu_loc(THEMES_BACK);
    for (;;)
    {
        int chosen_item = get_menu_selection(headers, MENU_THEMES, 0, 0);
        switch (chosen_item)
        {
            case THEME_REBOOT_RECOVERY:
            	ensure_path_unmounted("/sdcard");
                __reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART2, "recovery");
                break;
            case TW_THEME:
            	strcpy(tw_color_theme_val,"0");
                break;
            case CM_THEME:
            	strcpy(tw_color_theme_val,"1");
                break;
            case RED_THEME:
            	strcpy(tw_color_theme_val,"2");
                break;
            case GOOGLE_THEME:
            	strcpy(tw_color_theme_val,"3");
                break;
            case JF_THEME:
            	strcpy(tw_color_theme_val,"4");
                break;
            case THEMES_BACK:
            	dec_menu_loc();
            	return;
        }
        if (go_home) {
        	dec_menu_loc();
	        return;
	    }
        write_s_file();
        break;
    }
	ui_end_menu();
    dec_menu_loc();
    twrp_themes_menu();
}

void set_theme(char* tw_theme)
{
	if (strcmp(tw_theme,"0") == 0) // TEAMWIN THEME (default)
	{
		//HEADER_TEXT_COLOR
		htc.r = 255;
		htc.g = 255;
		htc.b = 255;
		htc.a = 255;

		//MENU_ITEM_COLOR
		mtc.r = 0;
		mtc.g = 255;
		mtc.b = 0;
		mtc.a = 255;

		//UI_PRINT_COLOR
		upc.r = 0;
		upc.g = 255;
		upc.b = 0;
		upc.a = 255;

		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 0;
		mihc.g = 255;
		mihc.b = 0;
		mihc.a = 255;

		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;

		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 0;
		mhebc.g = 255;
		mhebc.b = 0;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"1") == 0) // CM theme
	{
		htc.r = 193;
		htc.g = 193;
		htc.b = 193;
		htc.a = 255;

		mtc.r = 61;
		mtc.g = 233;
		mtc.b = 255;
		mtc.a = 255;

		upc.r = 193;
		upc.g = 193;
		upc.b = 193;
		upc.a = 255;

		mihc.r = 61;
		mihc.g = 233;
		mihc.b = 255;
		mihc.a = 255;

		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		
		mhebc.r = 61;
		mhebc.g = 233;
		mhebc.b = 255;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"2") == 0) // RED
	{
		htc.r = 128;
		htc.g = 0;
		htc.b = 0;
		htc.a = 255;

		mtc.r = 255;
		mtc.g = 0;
		mtc.b = 0;
		mtc.a = 255;

		upc.r = 255;
		upc.g = 0;
		upc.b = 0;
		upc.a = 255;

		mihc.r = 255;
		mihc.g = 0;
		mihc.b = 0;
		mihc.a = 255;

		miwhc.r = 255;
		miwhc.g = 255;
		miwhc.b = 255;
		miwhc.a = 255;
		
		mhebc.r = 255;
		mhebc.g = 0;
		mhebc.b = 0;
		mhebc.a = 255;
	}
	if (strcmp(tw_theme,"3") == 0) // GOOGLE
	{
		//HEADER_TEXT_COLOR
		htc.r = 255;
		htc.g = 255;
		htc.b = 255;
		htc.a = 255;
		//MENU_ITEM_COLOR
		mtc.r = 64;
		mtc.g = 96;
		mtc.b = 255;
		mtc.a = 255;
		//UI_PRINT_COLOR
		upc.r = 255;
		upc.g = 255;
		upc.b = 0;
		upc.a = 255;
		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 64;
		mihc.g = 96;
		mihc.b = 255;
		mihc.a = 255;
		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 0;
		mhebc.g = 0;
		mhebc.b = 0;
		mhebc.a = 0;
	}
	if (strcmp(tw_theme,"4") == 0) // JesusFreke
	{
		//HEADER_TEXT_COLOR
		htc.r = 255;
		htc.g = 255;
		htc.b = 255;
		htc.a = 255;
		//MENU_ITEM_COLOR
		mtc.r = 61;
		mtc.g = 96;
		mtc.b = 255;
		mtc.a = 255;
		//UI_PRINT_COLOR
		upc.r = 255;
		upc.g = 255;
		upc.b = 0;
		upc.a = 255;
		//MENU_ITEM_HIGHLIGHT_COLOR
		mihc.r = 61;
		mihc.g = 96;
		mihc.b = 255;
		mihc.a = 255;
		//MENU_ITEM_WHEN_HIGHLIGHTED_COLOR
		miwhc.r = 0;
		miwhc.g = 0;
		miwhc.b = 0;
		miwhc.a = 0;
		//MENU_HORIZONTAL_END_BAR_COLOR
		mhebc.r = 61;
		mhebc.g = 96;
		mhebc.b = 255;
		mhebc.a = 255;
	}
}
