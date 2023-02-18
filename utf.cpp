uint8_t UTF8ToUnicode(uint8_t *utf8, uint32_t *unicode)
{
    const uint8_t lut_size = 3;
    const uint8_t length_lut[] =
    {
        2, 3, 4
    };
    const uint8_t range_lut[] =
    {
        0xE0, 0xF0, 0xF8
    };
    const uint8_t mask_lut[] =
    {
        0x1F, 0x0F, 0x07
    };
    uint8_t length = 0;
    byte b = *(utf8 + 0);
    uint32_t i = 0;
    if (utf8 == NULL)
    {
        *unicode = 0;
        return 1;
    }
    if (b < 0x80)
    {
        *unicode = b;
        return 1;
    }
    if (b < 0xC0 || b > 0xFD)
    {
        *unicode = 0;
        return 1;
    }
    for (i = 0; i < lut_size; i++)
    {
        if (b < range_lut[i])
        {
            *unicode = b &mask_lut[i];
            length = length_lut[i];
            break;
        }
    }
    if (length == 0)
    {
        *unicode = 0;
        return 1;
    }
    for (i = 1; i < length; i++)
    {
        b = *(utf8 + i);
        if (b < 0x80 || b > 0xBF)
        {
            break;
        }
        *unicode <<= 6;
        *unicode |= (b &0x3F);
    }
    return (i < length) ? 1 : length;
}

uint8_t UnicodeToUTF16(uint32_t unicode, uint16_t *utf16)
{
    if (unicode <= 0xFFFF)
    {
        if (utf16 != NULL)
        {
            *utf16 = (unicode &0xFFFF);
        }
        return 1;
    }
    else if (unicode <= 0xEFFFF)
    {
        if (utf16 != NULL)
        {
            *(utf16 + 0) = 0xD800 + (unicode >> 10) - 0x40;
            *(utf16 + 1) = 0xDC00 + (unicode &0x03FF);
        }
        return 2;
    }
    return 0;
}