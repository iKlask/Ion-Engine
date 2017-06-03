#ifndef COLOR_H
#define COLOR_H

#include "Vect.h"
/////////////////////////////////////////////////
/// \struct Color
///	\brief Struct of saved color vector values
///
///	A collection of 140 different color values saved as vectors.
/////////////////////////////////////////////////
namespace Color
{
	// Standard colors (Red/Green/Blue/Alpha)
	static const Vect AliceBlue				=	{ 0.941176534f, 0.972549081f, 1.000000000f, 1.000000000f };		/*!< Color Vect for AliceBlue				 */
	static const Vect AntiqueWhite			=	{ 0.980392218f, 0.921568692f, 0.843137324f, 1.000000000f };		/*!< Color Vect for AntiqueWhite			 */
	static const Vect Aqua					=	{ 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Aqua					 */
	static const Vect Aquamarine			=	{ 0.498039246f, 1.000000000f, 0.831372619f, 1.000000000f };		/*!< Color Vect for Aquamarine				 */
	static const Vect Azure					=	{ 0.941176534f, 1.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Azure					 */
	static const Vect Beige					=	{ 0.960784376f, 0.960784376f, 0.862745166f, 1.000000000f };		/*!< Color Vect for Beige					 */
	static const Vect Bisque				=	{ 1.000000000f, 0.894117713f, 0.768627524f, 1.000000000f };		/*!< Color Vect for Bisque					 */
	static const Vect Black					=	{ 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Black					 */
	static const Vect BlanchedAlmond		=	{ 1.000000000f, 0.921568692f, 0.803921640f, 1.000000000f };		/*!< Color Vect for BlanchedAlmond			 */
	static const Vect Blue					=	{ 0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Blue					 */
	static const Vect BlueViolet			=	{ 0.541176498f, 0.168627456f, 0.886274576f, 1.000000000f };		/*!< Color Vect for BlueViolet				 */
	static const Vect Brown					=	{ 0.647058845f, 0.164705887f, 0.164705887f, 1.000000000f };		/*!< Color Vect for Brown					 */
	static const Vect BurlyWood				=	{ 0.870588303f, 0.721568644f, 0.529411793f, 1.000000000f };		/*!< Color Vect for BurlyWood				 */
	static const Vect CadetBlue				=	{ 0.372549027f, 0.619607866f, 0.627451003f, 1.000000000f };		/*!< Color Vect for CadetBlue				 */
	static const Vect Chartreuse			=	{ 0.498039246f, 1.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Chartreuse				 */
	static const Vect Chocolate				=	{ 0.823529482f, 0.411764741f, 0.117647067f, 1.000000000f };		/*!< Color Vect for Chocolate				 */
	static const Vect Coral					=	{ 1.000000000f, 0.498039246f, 0.313725501f, 1.000000000f };		/*!< Color Vect for Coral					 */
	static const Vect CornflowerBlue		=	{ 0.392156899f, 0.584313750f, 0.929411829f, 1.000000000f };		/*!< Color Vect for CornflowerBlue			 */
	static const Vect Cornsilk				=	{ 1.000000000f, 0.972549081f, 0.862745166f, 1.000000000f };		/*!< Color Vect for Cornsilk				 */
	static const Vect Crimson				=	{ 0.862745166f, 0.078431375f, 0.235294133f, 1.000000000f };		/*!< Color Vect for Crimson					 */
	static const Vect Cyan					=	{ 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Cyan					 */
	static const Vect DarkBlue				=	{ 0.000000000f, 0.000000000f, 0.545098066f, 1.000000000f };		/*!< Color Vect for DarkBlue				 */
	static const Vect DarkCyan				=	{ 0.000000000f, 0.545098066f, 0.545098066f, 1.000000000f };		/*!< Color Vect for DarkCyan				 */
	static const Vect DarkGoldenrod			=	{ 0.721568644f, 0.525490224f, 0.043137256f, 1.000000000f };		/*!< Color Vect for DarkGoldenrod			 */
	static const Vect DarkGray				=	{ 0.662745118f, 0.662745118f, 0.662745118f, 1.000000000f };		/*!< Color Vect for DarkGray				 */
	static const Vect DarkGreen				=	{ 0.000000000f, 0.392156899f, 0.000000000f, 1.000000000f };		/*!< Color Vect for DarkGreen				 */
	static const Vect DarkKhaki				=	{ 0.741176486f, 0.717647076f, 0.419607878f, 1.000000000f };		/*!< Color Vect for DarkKhaki				 */
	static const Vect DarkMagenta			=	{ 0.545098066f, 0.000000000f, 0.545098066f, 1.000000000f };		/*!< Color Vect for DarkMagenta				 */
	static const Vect DarkOliveGreen		=	{ 0.333333343f, 0.419607878f, 0.184313729f, 1.000000000f };		/*!< Color Vect for DarkOliveGreen			 */
	static const Vect DarkOrange			=	{ 1.000000000f, 0.549019635f, 0.000000000f, 1.000000000f };		/*!< Color Vect for DarkOrange				 */
	static const Vect DarkOrchid			=	{ 0.600000024f, 0.196078449f, 0.800000072f, 1.000000000f };		/*!< Color Vect for DarkOrchid				 */
	static const Vect DarkRed				=	{ 0.545098066f, 0.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for DarkRed					 */
	static const Vect DarkSalmon			=	{ 0.913725555f, 0.588235319f, 0.478431404f, 1.000000000f };		/*!< Color Vect for DarkSalmon				 */
	static const Vect DarkSeaGreen			=	{ 0.560784340f, 0.737254918f, 0.545098066f, 1.000000000f };		/*!< Color Vect for DarkSeaGreen			 */
	static const Vect DarkSlateBlue			=	{ 0.282352954f, 0.239215702f, 0.545098066f, 1.000000000f };		/*!< Color Vect for DarkSlateBlue			 */
	static const Vect DarkSlateGray			=	{ 0.184313729f, 0.309803933f, 0.309803933f, 1.000000000f };		/*!< Color Vect for DarkSlateGray			 */
	static const Vect DarkTurquoise			=	{ 0.000000000f, 0.807843208f, 0.819607913f, 1.000000000f };		/*!< Color Vect for DarkTurquoise			 */
	static const Vect DarkViolet			=	{ 0.580392182f, 0.000000000f, 0.827451050f, 1.000000000f };		/*!< Color Vect for DarkViolet				 */
	static const Vect DeepPink				=	{ 1.000000000f, 0.078431375f, 0.576470613f, 1.000000000f };		/*!< Color Vect for DeepPink				 */
	static const Vect DeepSkyBlue			=	{ 0.000000000f, 0.749019623f, 1.000000000f, 1.000000000f };		/*!< Color Vect for DeepSkyBlue				 */
	static const Vect DimGray				=	{ 0.411764741f, 0.411764741f, 0.411764741f, 1.000000000f };		/*!< Color Vect for DimGray					 */
	static const Vect DodgerBlue			=	{ 0.117647067f, 0.564705908f, 1.000000000f, 1.000000000f };		/*!< Color Vect for DodgerBlue				 */
	static const Vect Firebrick				=	{ 0.698039234f, 0.133333340f, 0.133333340f, 1.000000000f };		/*!< Color Vect for Firebrick				 */
	static const Vect FloralWhite			=	{ 1.000000000f, 0.980392218f, 0.941176534f, 1.000000000f };		/*!< Color Vect for FloralWhite				 */
	static const Vect ForestGreen			=	{ 0.133333340f, 0.545098066f, 0.133333340f, 1.000000000f };		/*!< Color Vect for ForestGreen				 */
	static const Vect Fuchsia				=	{ 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Fuchsia					 */
	static const Vect Gainsboro				=	{ 0.862745166f, 0.862745166f, 0.862745166f, 1.000000000f };		/*!< Color Vect for Gainsboro				 */
	static const Vect GhostWhite			=	{ 0.972549081f, 0.972549081f, 1.000000000f, 1.000000000f };		/*!< Color Vect for GhostWhite				 */
	static const Vect Gold					=	{ 1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Gold					 */
	static const Vect Goldenrod				=	{ 0.854902029f, 0.647058845f, 0.125490203f, 1.000000000f };		/*!< Color Vect for Goldenrod				 */
	static const Vect Gray					=	{ 0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f };		/*!< Color Vect for Gray					 */
	static const Vect Green					=	{ 0.000000000f, 0.501960814f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Green					 */
	static const Vect GreenYellow			=	{ 0.678431392f, 1.000000000f, 0.184313729f, 1.000000000f };		/*!< Color Vect for GreenYellow				 */
	static const Vect Honeydew				=	{ 0.941176534f, 1.000000000f, 0.941176534f, 1.000000000f };		/*!< Color Vect for Honeydew				 */
	static const Vect HotPink				=	{ 1.000000000f, 0.411764741f, 0.705882370f, 1.000000000f };		/*!< Color Vect for HotPink					 */
	static const Vect IndianRed				=	{ 0.803921640f, 0.360784322f, 0.360784322f, 1.000000000f };		/*!< Color Vect for IndianRed				 */
	static const Vect Indigo				=	{ 0.294117659f, 0.000000000f, 0.509803951f, 1.000000000f };		/*!< Color Vect for Indigo					 */
	static const Vect Ivory					=	{ 1.000000000f, 1.000000000f, 0.941176534f, 1.000000000f };		/*!< Color Vect for Ivory					 */
	static const Vect Khaki					=	{ 0.941176534f, 0.901960850f, 0.549019635f, 1.000000000f };		/*!< Color Vect for Khaki					 */
	static const Vect Lavender				=	{ 0.901960850f, 0.901960850f, 0.980392218f, 1.000000000f };		/*!< Color Vect for Lavender				 */
	static const Vect LavenderBlush			=	{ 1.000000000f, 0.941176534f, 0.960784376f, 1.000000000f };		/*!< Color Vect for LavenderBlush			 */
	static const Vect LawnGreen				=	{ 0.486274540f, 0.988235354f, 0.000000000f, 1.000000000f };		/*!< Color Vect for LawnGreen				 */
	static const Vect LemonChiffon			=	{ 1.000000000f, 0.980392218f, 0.803921640f, 1.000000000f };		/*!< Color Vect for LemonChiffon			 */
	static const Vect LightBlue				=	{ 0.678431392f, 0.847058892f, 0.901960850f, 1.000000000f };		/*!< Color Vect for LightBlue				 */
	static const Vect LightCoral			=	{ 0.941176534f, 0.501960814f, 0.501960814f, 1.000000000f };		/*!< Color Vect for LightCoral				 */
	static const Vect LightCyan				=	{ 0.878431439f, 1.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for LightCyan				 */
	static const Vect LightGoldenrodYellow	=	{ 0.980392218f, 0.980392218f, 0.823529482f, 1.000000000f };		/*!< Color Vect for LightGoldenrodYellow	 */
	static const Vect LightGreen			=	{ 0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f };		/*!< Color Vect for LightGreen				 */
	static const Vect LightGray				=	{ 0.827451050f, 0.827451050f, 0.827451050f, 1.000000000f };		/*!< Color Vect for LightGray				 */
	static const Vect LightPink				=	{ 1.000000000f, 0.713725507f, 0.756862819f, 1.000000000f };		/*!< Color Vect for LightPink				 */
	static const Vect LightSalmon			=	{ 1.000000000f, 0.627451003f, 0.478431404f, 1.000000000f };		/*!< Color Vect for LightSalmon				 */
	static const Vect LightSeaGreen			=	{ 0.125490203f, 0.698039234f, 0.666666687f, 1.000000000f };		/*!< Color Vect for LightSeaGreen			 */
	static const Vect LightSkyBlue			=	{ 0.529411793f, 0.807843208f, 0.980392218f, 1.000000000f };		/*!< Color Vect for LightSkyBlue			 */
	static const Vect LightSlateGray		=	{ 0.466666698f, 0.533333361f, 0.600000024f, 1.000000000f };		/*!< Color Vect for LightSlateGray			 */
	static const Vect LightSteelBlue		=	{ 0.690196097f, 0.768627524f, 0.870588303f, 1.000000000f };		/*!< Color Vect for LightSteelBlue			 */
	static const Vect LightYellow			=	{ 1.000000000f, 1.000000000f, 0.878431439f, 1.000000000f };		/*!< Color Vect for LightYellow				 */
	static const Vect Lime					=	{ 0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Lime					 */
	static const Vect LimeGreen				=	{ 0.196078449f, 0.803921640f, 0.196078449f, 1.000000000f };		/*!< Color Vect for LimeGreen				 */
	static const Vect Linen					=	{ 0.980392218f, 0.941176534f, 0.901960850f, 1.000000000f };		/*!< Color Vect for Linen					 */
	static const Vect Magenta				=	{ 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for Magenta					 */
	static const Vect Maroon				=	{ 0.501960814f, 0.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Maroon					 */
	static const Vect MediumAquamarine		=	{ 0.400000036f, 0.803921640f, 0.666666687f, 1.000000000f };		/*!< Color Vect for MediumAquamarine		 */
	static const Vect MediumBlue			=	{ 0.000000000f, 0.000000000f, 0.803921640f, 1.000000000f };		/*!< Color Vect for MediumBlue				 */
	static const Vect MediumOrchid			=	{ 0.729411781f, 0.333333343f, 0.827451050f, 1.000000000f };		/*!< Color Vect for MediumOrchid			 */
	static const Vect MediumPurple			=	{ 0.576470613f, 0.439215720f, 0.858823597f, 1.000000000f };		/*!< Color Vect for MediumPurple			 */
	static const Vect MediumSeaGreen		=	{ 0.235294133f, 0.701960802f, 0.443137288f, 1.000000000f };		/*!< Color Vect for MediumSeaGreen			 */
	static const Vect MediumSlateBlue		=	{ 0.482352972f, 0.407843173f, 0.933333397f, 1.000000000f };		/*!< Color Vect for MediumSlateBlue			 */
	static const Vect MediumSpringGreen		=	{ 0.000000000f, 0.980392218f, 0.603921592f, 1.000000000f };		/*!< Color Vect for MediumSpringGreen		 */
	static const Vect MediumTurquoise		=	{ 0.282352954f, 0.819607913f, 0.800000072f, 1.000000000f };		/*!< Color Vect for MediumTurquoise			 */
	static const Vect MediumVioletRed		=	{ 0.780392230f, 0.082352944f, 0.521568656f, 1.000000000f };		/*!< Color Vect for MediumVioletRed			 */
	static const Vect MidnightBlue			=	{ 0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f };		/*!< Color Vect for MidnightBlue			 */
	static const Vect MintCream				=	{ 0.960784376f, 1.000000000f, 0.980392218f, 1.000000000f };		/*!< Color Vect for MintCream				 */
	static const Vect MistyRose				=	{ 1.000000000f, 0.894117713f, 0.882353008f, 1.000000000f };		/*!< Color Vect for MistyRose				 */
	static const Vect Moccasin				=	{ 1.000000000f, 0.894117713f, 0.709803939f, 1.000000000f };		/*!< Color Vect for Moccasin				 */
	static const Vect NavajoWhite			=	{ 1.000000000f, 0.870588303f, 0.678431392f, 1.000000000f };		/*!< Color Vect for NavajoWhite				 */
	static const Vect Navy					=	{ 0.000000000f, 0.000000000f, 0.501960814f, 1.000000000f };		/*!< Color Vect for Navy					 */
	static const Vect OldLace				=	{ 0.992156923f, 0.960784376f, 0.901960850f, 1.000000000f };		/*!< Color Vect for OldLace					 */
	static const Vect Olive					=	{ 0.501960814f, 0.501960814f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Olive					 */
	static const Vect OliveDrab				=	{ 0.419607878f, 0.556862772f, 0.137254909f, 1.000000000f };		/*!< Color Vect for OliveDrab				 */
	static const Vect Orange				=	{ 1.000000000f, 0.647058845f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Orange					 */
	static const Vect OrangeRed				=	{ 1.000000000f, 0.270588249f, 0.000000000f, 1.000000000f };		/*!< Color Vect for OrangeRed				 */
	static const Vect Orchid				=	{ 0.854902029f, 0.439215720f, 0.839215755f, 1.000000000f };		/*!< Color Vect for Orchid					 */
	static const Vect PaleGoldenrod			=	{ 0.933333397f, 0.909803987f, 0.666666687f, 1.000000000f };		/*!< Color Vect for PaleGoldenrod			 */
	static const Vect PaleGreen				=	{ 0.596078455f, 0.984313786f, 0.596078455f, 1.000000000f };		/*!< Color Vect for PaleGreen				 */
	static const Vect PaleTurquoise			=	{ 0.686274529f, 0.933333397f, 0.933333397f, 1.000000000f };		/*!< Color Vect for PaleTurquoise			 */
	static const Vect PaleVioletRed			=	{ 0.858823597f, 0.439215720f, 0.576470613f, 1.000000000f };		/*!< Color Vect for PaleVioletRed			 */
	static const Vect PapayaWhip			=	{ 1.000000000f, 0.937254965f, 0.835294187f, 1.000000000f };		/*!< Color Vect for PapayaWhip				 */
	static const Vect PeachPuff				=	{ 1.000000000f, 0.854902029f, 0.725490212f, 1.000000000f };		/*!< Color Vect for PeachPuff				 */
	static const Vect Peru					=	{ 0.803921640f, 0.521568656f, 0.247058839f, 1.000000000f };		/*!< Color Vect for Peru					 */
	static const Vect Pink					=	{ 1.000000000f, 0.752941251f, 0.796078503f, 1.000000000f };		/*!< Color Vect for Pink					 */
	static const Vect Plum					=	{ 0.866666734f, 0.627451003f, 0.866666734f, 1.000000000f };		/*!< Color Vect for Plum					 */
	static const Vect PowderBlue			=	{ 0.690196097f, 0.878431439f, 0.901960850f, 1.000000000f };		/*!< Color Vect for PowderBlue				 */
	static const Vect Purple				=	{ 0.501960814f, 0.000000000f, 0.501960814f, 1.000000000f };		/*!< Color Vect for Purple					 */
	static const Vect Red					=	{ 1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Red						 */
	static const Vect RosyBrown				=	{ 0.737254918f, 0.560784340f, 0.560784340f, 1.000000000f };		/*!< Color Vect for RosyBrown				 */
	static const Vect RoyalBlue				=	{ 0.254901975f, 0.411764741f, 0.882353008f, 1.000000000f };		/*!< Color Vect for RoyalBlue				 */
	static const Vect SaddleBrown			=	{ 0.545098066f, 0.270588249f, 0.074509807f, 1.000000000f };		/*!< Color Vect for SaddleBrown				 */
	static const Vect Salmon				=	{ 0.980392218f, 0.501960814f, 0.447058856f, 1.000000000f };		/*!< Color Vect for Salmon					 */
	static const Vect SandyBrown			=	{ 0.956862807f, 0.643137276f, 0.376470625f, 1.000000000f };		/*!< Color Vect for SandyBrown				 */
	static const Vect SeaGreen				=	{ 0.180392161f, 0.545098066f, 0.341176480f, 1.000000000f };		/*!< Color Vect for SeaGreen				 */
	static const Vect SeaShell				=	{ 1.000000000f, 0.960784376f, 0.933333397f, 1.000000000f };		/*!< Color Vect for SeaShell				 */
	static const Vect Sienna				=	{ 0.627451003f, 0.321568638f, 0.176470593f, 1.000000000f };		/*!< Color Vect for Sienna					 */
	static const Vect Silver				=	{ 0.752941251f, 0.752941251f, 0.752941251f, 1.000000000f };		/*!< Color Vect for Silver					 */
	static const Vect SkyBlue				=	{ 0.529411793f, 0.807843208f, 0.921568692f, 1.000000000f };		/*!< Color Vect for SkyBlue					 */
	static const Vect SlateBlue				=	{ 0.415686309f, 0.352941185f, 0.803921640f, 1.000000000f };		/*!< Color Vect for SlateBlue				 */
	static const Vect SlateGray				=	{ 0.439215720f, 0.501960814f, 0.564705908f, 1.000000000f };		/*!< Color Vect for SlateGray				 */
	static const Vect Snow					=	{ 1.000000000f, 0.980392218f, 0.980392218f, 1.000000000f };		/*!< Color Vect for Snow					 */
	static const Vect SpringGreen			=	{ 0.000000000f, 1.000000000f, 0.498039246f, 1.000000000f };		/*!< Color Vect for SpringGreen				 */
	static const Vect SteelBlue				=	{ 0.274509817f, 0.509803951f, 0.705882370f, 1.000000000f };		/*!< Color Vect for SteelBlue				 */
	static const Vect Tan					=	{ 0.823529482f, 0.705882370f, 0.549019635f, 1.000000000f };		/*!< Color Vect for Tan						 */
	static const Vect Teal					=	{ 0.000000000f, 0.501960814f, 0.501960814f, 1.000000000f };		/*!< Color Vect for Teal					 */
	static const Vect Thistle				=	{ 0.847058892f, 0.749019623f, 0.847058892f, 1.000000000f };		/*!< Color Vect for Thistle					 */
	static const Vect Tomato				=	{ 1.000000000f, 0.388235331f, 0.278431386f, 1.000000000f };		/*!< Color Vect for Tomato					 */
	static const Vect Transparent			=	{ 0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f };		/*!< Color Vect for Transparent				 */
	static const Vect Turquoise				=	{ 0.250980407f, 0.878431439f, 0.815686345f, 1.000000000f };		/*!< Color Vect for Turquoise				 */
	static const Vect Violet				=	{ 0.933333397f, 0.509803951f, 0.933333397f, 1.000000000f };		/*!< Color Vect for Violet					 */
	static const Vect Wheat					=	{ 0.960784376f, 0.870588303f, 0.701960802f, 1.000000000f };		/*!< Color Vect for Wheat					 */
	static const Vect White					=	{ 1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };		/*!< Color Vect for White					 */
	static const Vect WhiteSmoke			=	{ 0.960784376f, 0.960784376f, 0.960784376f, 1.000000000f };		/*!< Color Vect for WhiteSmoke				 */
	static const Vect Yellow				=	{ 1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };		/*!< Color Vect for Yellow					 */
	static const Vect YellowGreen			=	{ 0.603921592f, 0.803921640f, 0.196078449f, 1.000000000f };		/*!< Color Vect for YellowGreen				 */
};
#endif COLOR_H