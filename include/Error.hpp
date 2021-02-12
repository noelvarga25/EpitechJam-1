/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Error
*/

#pragma once

namespace Err
{
    enum Code {
        NONE,
        INVALID_FILE,
        LINE_ERROR,
        FAIL_LOAD_IMG,
        FAIL_LOAD_FONT,
        WRONG_EXT,
        ID_TXTR_OVERFLOW,
        ID_FONT_OVERFLOW,
        NOT_INIT_VAR,
        INVALID_ID,
        INVALID_SIZE
    };
}