import {
  Body,
  Controller,
  Delete,
  Get,
  Param,
  Post,
  Put,
  Query,
} from '@nestjs/common';
import { BookmarkService } from './bookmark.service';
import { Bookmark } from './schemas/bookmark.schema';
import type { UpdateBookmarkDto } from './dto/updateBookmarkDto';
import { BookmarkResponse } from './dto/bookmarksResponse.dto';
import type { CreateBookmarkDto } from './dto/createBookmarkDto';
import { ErrorDto } from './dto/error.dto';
import { SuccessResponse } from './dto/success.dto';

@Controller('bookmarks')
export class BookmarkController {
  constructor(private readonly BookmarkService: BookmarkService) {}

  @Get()
  async getBookmarks(
    @Query('limit') limit?: number,
    @Query('page') page?: number,
  ): Promise<BookmarkResponse> {
    return this.BookmarkService.getBookmarks(limit || 10, page || 1);
  }
  @Get(':id')
  async getBookmarkById(@Param('id') id: string): Promise<Bookmark | ErrorDto> {
    return this.BookmarkService.getBookmarkById(id);
  }

  @Post()
  async createBookmark(@Body() dto: CreateBookmarkDto): Promise<Bookmark> {
    return this.BookmarkService.createBookmark(dto);
  }

  @Put(':id')
  updateBookmark(
    @Param('id') id: string,
    @Body() dto: UpdateBookmarkDto,
  ): Promise<Bookmark | ErrorDto> {
    return this.BookmarkService.updateBookmark(id, dto);
  }

  @Delete(':id')
  deleteBookmark(@Param('id') id: string): Promise<SuccessResponse> {
    return this.BookmarkService.deleteBookmarks(id);
  }
}
