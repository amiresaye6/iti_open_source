import { Injectable } from '@nestjs/common';
import { Bookmark, BookmarkDocument } from './schemas/bookmark.schema';
import { InjectModel } from '@nestjs/mongoose';
import { Model } from 'mongoose';
import { CreateBookmarkDto } from './dto/createBookmarkDto';
import { UpdateBookmarkDto } from './dto/updateBookmarkDto';
import { BookmarkResponse } from './dto/bookmarksResponse.dto';
import { ErrorDto } from './dto/error.dto';
import { SuccessResponse } from './dto/success.dto';

@Injectable()
export class BookmarkService {
  constructor(
    @InjectModel(Bookmark.name) private bookmarkModel: Model<BookmarkDocument>,
  ) {}
  async getBookmarks(limit: number, page: number): Promise<BookmarkResponse> {
    const data: Bookmark[] = await this.bookmarkModel
      .find()
      .limit(limit)
      .skip((page - 1) * limit);

    const total: number = await this.bookmarkModel.countDocuments();
    return {
      message: 'get all bookmarks',
      data,
      pagination: {
        limit: +limit,
        currentPage: +page,
        pages: Math.ceil(total / limit),
        total,
      },
    };
  }
  async getBookmarkById(id: string): Promise<Bookmark | ErrorDto> {
    const bm = (await this.bookmarkModel.findById(id)) || {
      message: 'there is no bookmark found with this id',
      success: false,
    };
    return bm;
  }
  async createBookmark(dto: CreateBookmarkDto): Promise<Bookmark> {
    const bm = new this.bookmarkModel(dto);
    return bm.save();
  }
  async updateBookmark(
    id: string,
    dto: UpdateBookmarkDto,
  ): Promise<Bookmark | ErrorDto> {
    const bm = await this.bookmarkModel
      .findByIdAndUpdate(id, dto, { after: true })
      .exec();
    return bm || { message: 'bookmark not found', success: false };
  }
  async deleteBookmarks(id: string): Promise<SuccessResponse | ErrorDto> {
    const bm: object | null = await this.bookmarkModel.findByIdAndDelete(id);
    if (!bm)
      return {
        message: 'no bookmark found with this id',
        success: false,
      };
    return { message: 'bookmark deleted successfully', success: true };
  }
}
