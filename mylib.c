/*
 *FUNCTION
 *mmi_ucs2str
 *DESCRIPTION
 *Find the first occurrence of string2 in string1
 *PARAMETERS
 *str1		[IN] string to search in.
 *str2		[IN] string to search for.
 *RETURNS
 *returns a pointer to the first occurrence of string2 in
 *string1, or NULL if string2 does not occur in string1
*/
S8 *mmi_ucs2str(const S8 *str1, const S8 *str2)
{
	S8 *cp = (S8*)str1;
	S8 *s1, *s2;
	
	if(!(*str1 || *(str2+1)))
	{
		return ((S8*)str1);
	}
	
	while(*cp || *(cp+1))
	{
		s1 = cp;
		s2 = (S8*)str2;
		
		while((*s1 || *(s1+1))
			&& (*s2 || *(s2+1))
			&& !((*s1-*s2) || (*(s1+1)-*(s2+1))))
		{
			s1 += 2;
			s2 += 2;
		}
		
		if(!(*s2 || *(s2+1)))
		{
			return (cp);
		}
		
		cp += 2;
	}
	
	return NULL;
}